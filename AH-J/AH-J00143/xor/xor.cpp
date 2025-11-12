#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],b[N],ma=-1;
void dfs(int I,int s)
{
	if(I>n)
	{
		ma=max(ma,s);
		return;
	}
	dfs(I+1,s);
	if(b[I]!=-1)
	{
		dfs(b[I]+1,s+1);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			b[i]=i;
		}
		for(int j=i+1,w=a[i];j<=n;j++)
		{
			w^=a[j];
			if(w==k)
			{
				b[i]=j;
				break;
			}
		}
	}
	dfs(1,0);
	cout<<max(ma,0);
	return 0;
}
//AC!!!!
