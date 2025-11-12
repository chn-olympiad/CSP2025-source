#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int test,n;
int a[N][3],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>test;
	while(test--){
		cin>>n;
		long long ans=0;
		int n0=0,n1=0,n2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int mx=max(max(a[i][0],a[i][1]),a[i][2]);
			if(mx==a[i][0]) ++n0,ans+=1ll*a[i][0],b[i]=0;
			else if(mx==a[i][1]) ++n1,ans+=1ll*a[i][1],b[i]=1;
			else ++n2,ans+=1ll*a[i][2],b[i]=2;
		}
		if(max(max(n0,n1),n2)<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		if(n0>n/2){
			int cl=0;
			for(int i=1;i<=n;i++){
				if(b[i]==0){
					c[++cl]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
				}
			}
			sort(c+1,c+cl+1);
			for(int i=1;i<=cl-n/2;i++){
				ans-=1ll*c[i];
			}
		}
		if(n1>n/2){
			int cl=0;
			for(int i=1;i<=n;i++){
				if(b[i]==1){
					c[++cl]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
				}
			}
			sort(c+1,c+cl+1);
			for(int i=1;i<=cl-n/2;i++){
				ans-=1ll*c[i];
			}
		}
		if(n2>n/2){
			int cl=0;
			for(int i=1;i<=n;i++){
				if(b[i]==2){
					c[++cl]=min(a[i][2]-a[i][0],a[i][2]-a[i][1]);
				}
			}
			sort(c+1,c+cl+1);
			for(int i=1;i<=cl-n/2;i++){
				ans-=1ll*c[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
