#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,ss;
struct a
{
	string x,y;
}t[20];
int dfs(string x)
{
	cout<<x<<endl;
	if(x==ss)
	{
		return 1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=x.length()-t[i].x.length();j++)
		{
			bool f=1;
			for(int z=j;z<=j+t[i].x.length()-1;z++)
			{
				if(x[z]!=t[i].x[z])
				{
					f=0;break;
				}
			}
			if(f)
			{
				for(int z=j;z<=j+t[i].x.length()-1;z++)
				{
					x[z]=t[i].y[z];
				}
				cnt+=dfs(x);
			}
		}
	}
	return cnt;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].x;
		cin>>t[i].y;	
	}
	while(m--)
	{
		cin>>s;
		cin>>ss;
		int ans=dfs(s);
		printf("%d",ans);
	}
	return 0;
} 
