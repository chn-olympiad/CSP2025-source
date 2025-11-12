#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,a,b,c;i<=m;i++) {
		cin>>a>>b>>c;
		ans+=b;
	}
	for(int i=1,t;i<=n+1;i++) cin>>t;
	cout<<ans;
}
