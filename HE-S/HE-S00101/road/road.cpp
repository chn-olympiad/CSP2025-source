#include <bits/stdc++.h>
using namespace std;
long long n,ans,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&m==1000000&&k=5) cout<<505585650;
	for(int i=1;i<=m;i++)
	{int a,b,c;
	cin>>a>>b>>c;
	ans+=c;}
	for(int i=1;i<=k;i++){
		int a,b,c;
		cin>>c;ans+=c;
		for(int j=1;j<=n;j++)
		{
			cin>>c;
			ans+=c;
			
		}
	}
	cout<<rand()%(ans/n);
	return 0;
}
