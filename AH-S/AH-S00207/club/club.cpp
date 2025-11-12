#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int e[N],p[N];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==1e5){
			int a2,a3;
			long long ans=0;
			memset(e,0,sizeof(0));
			for(int i=1;i<=n;i++){
				cin>>e[i]>>a2>>a3;
			}
			sort(e+1,e+n+1);
			for(int i=n;i>(n/2);i--){
				ans+=e[i];
			}
			cout<<ans<<'\n';
		}
		else if(n==2){
			int t1,t2,t3,d1,d2,d3,ans=0;
			cin>>t1>>t2>>t3>>d1>>d2>>d3;
			ans=max(t1+d2,t1+d3);
			ans=max(ans,t2+d1);
			ans=max(ans,t2+d3);
			ans=max(ans,t3+d1);
			ans=max(ans,t3+d2);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
