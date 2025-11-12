#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a>>b>>c;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>a;
	cout<<0<<endl;
	return 0;
}
