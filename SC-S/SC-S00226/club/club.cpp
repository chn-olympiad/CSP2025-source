#include<bits/stdc++.h>
using namespace std;
long long int n,t,used[4],a[100005][4],ans=-1,aa[100005],bb[100005];
bool flag1=0,flag2=0;
void go(long long int i,long long int j,long long int s){
	if(i>=n){
		if(ans<s){
			ans=s;
			return;
		}
		return;
	}
	for(int k=1;k<=3;k++){
		if(used[k]>0){
			used[k]--;
			go(i+1,k,s+a[i+1][k]);
			used[k]++;
		}
	}
	return;
}
bool cmp(long long int x,long long int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long int tt=1;tt<=t;tt++){
		ans=0;
		cin>>n;
		for(long long int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			aa[i]=a[i][1];
			bb[i]=a[i][2];
			if(a[i][2]==a[i][3]&&a[i][2]==0){
				flag1=0;
			}else{
				flag1=1;
			}
			if(a[i][3]!=0){
				flag2=1;
			}
		}
		used[1]=used[2]=used[3]=n/2;
		if(flag1=0){
			sort(aa+1,aa+n+1,cmp);
			for(long long int i=1;i<=n/2;i++){
				ans+=aa[i];
			}
			cout<<ans;
			continue;
		}
		go(0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}