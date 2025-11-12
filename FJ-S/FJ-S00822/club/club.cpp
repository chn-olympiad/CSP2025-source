#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct up{
	int a,b,c;
}s[N];
int n,ans=0,g=0,o[4];
void dfs(int c)
{
	if(c>n)
	{
		ans=max(ans,g);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		int k=g;
		if(o[i]<n/2)
		{
			if(i==1)
			o[i]++,g+=s[c].a;
			else if(i==2)
			o[i]++,g+=s[c].b;
			else
			o[i]++,g+=s[c].c;
		}
		else
		continue;
		dfs(c+1);
		g=k;
		o[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		}
		dfs(1);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
//无双 万军取首 
