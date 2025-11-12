#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s,x,p;
bool f;
map<int,priority_queue<int,vector<int>,greater<int> > >mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		x^=a[i];
		mp[x].push(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!mp[k^p].empty())
		{
			while(mp[k^p].top()<i&&!mp[k^p].empty())mp[k^p].pop();
			if(mp[k^p].empty())
			{
				p^=a[i];
				continue;
			}
			s++,i=mp[k^p].top();
			mp[k^p].pop();
			p^=k;
			continue;
		}
		p^=a[i];
	}
	printf("%d",s);
	return 0;
}
