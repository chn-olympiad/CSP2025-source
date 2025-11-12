#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],p[500005],l,ans,x,c;
map<int,int> b;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	b[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]^a[i];
		if(a[i]==k)
		{
			ans++;
			l=i;
		}else
		{
			
			x=k^p[i];
			c=b[x];
			if(c!=0||x==0)
			{
				if(c+1>l)
				{
					ans++;
					l=i;
				}
			}
		}
		b[p[i]]=i;
	}
	cout<<ans;
	return 0;
}