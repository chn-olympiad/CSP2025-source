#include<bits/stdc++.h>
using namespace std;
int t,n,ov,onum;long long cnt=0;
int dp[4];
struct cy{
	int s1,s2,s3;int smx,red;
}a[100010];
bool check(){
	int k=n/2;
	for(int i=1;i<=3;i++){
		if(dp[i]>k){
			ov=i;onum=dp[i]-k;
			return true;
		}
	} 
	return false;
}
bool cmp(cy i,cy j){
	return i.red<j.red; 
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;ov=0;onum=0;cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			if(a[i].s1>=a[i].s2&&a[i].s2>=a[i].s3) {
				a[i].smx=a[i].s1;dp[1]++;a[i].red=a[i].s1-a[i].s2;
			}
			else if(a[i].s1>=a[i].s3&&a[i].s3>=a[i].s2) {
				a[i].smx=a[i].s1;dp[1]++;a[i].red=a[i].s1-a[i].s3;
			}
			else if(a[i].s2>=a[i].s1&&a[i].s1>=a[i].s3) {
				a[i].smx=a[i].s2;dp[2]++;a[i].red=a[i].s2-a[i].s1;
			}
			else if(a[i].s2>=a[i].s3&&a[i].s3>=a[i].s1) {
				a[i].smx=a[i].s2;dp[2]++;a[i].red=a[i].s2-a[i].s3;
			}
			else if(a[i].s3>=a[i].s1&&a[i].s1>=a[i].s2) {
				a[i].smx=a[i].s3;dp[3]++;a[i].red=a[i].s3-a[i].s1;
			}
			else if(a[i].s3>=a[i].s2&&a[i].s2>=a[i].s1) {
				a[i].smx=a[i].s3;dp[3]++;a[i].red=a[i].s3-a[i].s2;
			}
			cnt+=a[i].smx;
		}
		
		if(check()){
			sort(a+1,a+1+n,cmp);
			for(int i=1,k=0;k<onum;i++){
				if(a[i].smx==a[i].s1&&ov==1){
					cnt-=a[i].red;k++;
				}
				else if(a[i].smx==a[i].s2&&ov==2){
					cnt-=a[i].red;k++;
				}
				else if(a[i].smx==a[i].s3&&ov==3){
					cnt-=a[i].red;k++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
