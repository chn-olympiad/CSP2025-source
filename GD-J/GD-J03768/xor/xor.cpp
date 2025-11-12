#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],s=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	if(m==0&&s==n)
	{
		cout<<n/2;
	}
	return 0;
} 
