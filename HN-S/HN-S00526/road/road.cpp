#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road .in","r",stdin);
	freopen("road .out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		ans+=a;
	}
	cout<<ans;
	return 0;
}

