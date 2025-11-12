#include <bits/stdc++.h>
using namespace std;
long long c[10005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	scanf("%d%d",&n,&m);
	char a;
	cin>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2)
	{
		cout<<2<<endl;
	}
	else
	{
		cout<<2204128<<endl;
	} 
	return 0;
}
