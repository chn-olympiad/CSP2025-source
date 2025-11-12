#include<bits/stdc++.h>
using namespace std;
int a,b,c,s[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c,k1,ans=0;
	cin>>n>>m>>k;
	for(int j=1;j<=m;j++){
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=n+1;i++){
		cin>>k1;
	}
	cout<<ans;
	return 0;
}
