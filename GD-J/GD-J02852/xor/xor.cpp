#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500100],b[500100],c[1100010],ss;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	c[0]=1;
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[b[i]^k]==1)
		{
			memset(c,0,sizeof(c));
			c[b[i]]=1;
			ss++;
		}
		else
		{
			c[b[i]]=1;
		}
	}
	cout<<ss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}  
