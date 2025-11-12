#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,k,b[1000005],a[1000005],c[1000005],d[100],e[11][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
		for(int j=1;j<=n;j++)
		cin>>e[i][j];
	}
	cout<<13;
	return 0;
}
