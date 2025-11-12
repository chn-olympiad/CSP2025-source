#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100000];
ll b[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	b[1]=1;
	for(int i=2;i<=n;i++)
	{
		b[i]=(b[i-1]*i)%998244353;
	}
	cout<<b[n];
	
	fclose(stdin);fclose(stdout);
	return 0;
}
