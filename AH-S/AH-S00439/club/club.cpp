#include<bits/stdc++.h>
using namespace std;
long long a[100005][10];
long long flag[100005];
long long change[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n;
		long long vae=0;
		long long ans=0;
		long long a1=0,a2=0,a3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			long long x=0;
			x=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=x;
			if(x==a[i][1]) {
				flag[i]=1;
				a1++;
			}
			else if(x==a[i][2]) {
				flag[i]=2;
				a2++;
			}
			else {
				flag[i]=3;
				a3++;
			}
		}
		long long cnt=0;
		if(a1>n/2){
			vae=a1-n/2;
			for(int i=1;i<=n;i++){
				if(flag[i]==1){
					cnt++;
					change[cnt]=min((a[i][1]-a[i][2]),(a[i][1]-a[i][3]));
				}
			}
		}
		if(a2>n/2){
			vae=a2-n/2;
			for(int i=1;i<=n;i++){
				if(flag[i]==2){
					cnt++;
					change[cnt]=min((a[i][2]-a[i][1]),(a[i][2]-a[i][3]));
				}
			}
		}
		if(a3>n/2){
			vae=a3-n/2;
			for(int i=1;i<=n;i++){
				if(flag[i]==3){
					cnt++;
					change[cnt]=min((a[i][3]-a[i][1]),(a[i][3]-a[i][2]));
				}
			}
		}
		sort(change+1,change+1+cnt);
		for(int i=1;i<=vae;i++){
			ans-=change[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
