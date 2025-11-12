#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long int n,k,ans=0,a[N],f[N];
struct node
{
	long long int f,l,r;
}b[N];
int minn=1e9;
int main()
{
	freopen("xor.in ","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ans++;
		f[i]=f[i-1]^a[i];
	}
	b[0].f=0;
	int c=1;
	for(int i=1;i<=n;i++) 
	{
		b[i]=b[i-1];
		for(int j=i;j>=1;j--) 
		{
			int x=f[i]^f[j-1];
			if(x==k&&b[i].f<b[i-j+1].f+1&&j>b[i-j+1].r) 
			{
				b[i].r=j;
				b[i].f=b[i-j+1].f+1;
			}
		}
	}
	cout<<b[n].f;
	return 0;
}
