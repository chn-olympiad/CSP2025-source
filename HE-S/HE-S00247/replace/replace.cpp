#include<bits/stdc++.h>
using namespace std;
char a[10001][5],b[10001][5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>b[i][1]>>b[i][2];
	}
	
	return 0; 
}
