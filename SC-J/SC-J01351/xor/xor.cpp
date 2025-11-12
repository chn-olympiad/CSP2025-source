#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,a[500050],ans,f[500050];
bool b[500050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=t;j<=i;j++)
		{
			f[j]=f[j]^a[i];
			if(f[j]==k)
			{
				ans++;
				t=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
 } 