#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+990;
ll n,m,k,f,t,s,x,y,a[maxn],d[maxn];
bool b[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1; i<=n; i++)
		cin>>a[i];
	for(ll i=1; i<=n; i++)
		d[i]=d[i-1]^a[i];
	memset(b,false,sizeof(b));
	if(k==1||k==0)
	{
		x=0;
		for(ll i=1; i<=n; i++)
		{
			f=d[x]^d[i];
			if(f==k)
			{
				x=i;
				s++;
				continue;
			}
		}
	}
	else
	{
		x=1;
		for(ll i=x; i<=n; i++)
		{
			t=0;
			for(ll j=i; j<=n; j++)
			{
				f=d[i-1]^d[j];
				if(f==k)
				{
					for(ll l=i; l<=j; l++)
					{
						if(b[l]==true)
						{
							t=1;
							break;
						}
					}
					if(t==1)
						break;
					for(ll l=i; l<=j; l++)
						b[l]=true;
					s++;
					x=j;
					break;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
