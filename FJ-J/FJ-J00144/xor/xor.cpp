#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll begin;
	ll over;
}c[500005];
ll n,a[500005],b[500005],j,k,sum;
bool cmp(Node a,Node b)
{
	return a.over<b.over;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if((b[j+i]^b[j-1])==k)
			{
				c[++c[0].begin].begin=j;
				c[c[0].begin].over=j+i;
			}
		}
	}
	sort(c+1,c+1+c[0].begin,cmp);
	for(int i=1;i<=c[0].begin;i++)
	{
		if(c[i].begin>c[j].over)
		{
			j=i;
			sum++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
