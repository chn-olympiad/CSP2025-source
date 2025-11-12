#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],ans;
bitset<2100000> c;
queue<int> q;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	c[0]=1;
	q.push(0);
	for(int i=1;i<=n;i++)
	{
		if(c[k^b[i]])
		{
			ans++;
			while(!q.empty())
			{
				c[q.front()]=0;
				q.pop();
			}
		}
		c[b[i]]=1;
		q.push(b[i]);
	}
	cout<<ans;
	return 0;
}
