#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s2=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			long long t=i;
			for(int n=i;n<=j;n++)
			{
				t=t^n;
			}
			if(t==k&&j-i+1>s2)
			{
				
				s2=j-i+1;
			}
		}
	}
	if(s2<0) cout<<1;
	else cout<<s2;
}