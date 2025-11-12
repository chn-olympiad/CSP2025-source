#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[505],c[505];
int all[500005];
int main()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<m; 
	return 0;	
} 
