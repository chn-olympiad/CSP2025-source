#include<bits/stdc++.h>
using namespace std;
int c[505],af[505],at[505];
int main()
{
	int n,m;
	long long a;
	freopen("employ.in","n",stdin);
	freopen("employ.in","m",stdin);
	freopen("employ.in","a",stdin);
	//cin>>n>>m>>a; 
	for(int i=1;i<=n;i++)
	{
		freopen("employ.in","c[i]",stdin);
		//cin>>c[i];
		af[i]=a%10;
		a/=10;
	}
	for(int i=1;i<=n;i++)
	{
		at[i]=af[n-i+1];
		freopen("employ.in","at[i]",stdout);
		//cout<<at[i];
	}
	return 0;
}


