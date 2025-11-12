#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum=0,p=0,q=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int a=100005;
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		a=min(b,a);
	}
	cout<<n-a;
	return 0;
}
