#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node
{
	string s1,s2;
}a[200005];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			int x=a[i].s1.size();
			int y=t1.size();
			for(int j=0;j<=y-x;j++)//qishi
			{
				bool f=0;
				for(int t=0;t<j;t++)
				{
					if(t1[t]!=t2[t])
					{
						f=1;
						break;
					}
				}
				if(f) continue;
				for(int t=j+x;t<y;t++)
				{
					if(t1[t]!=t2[t])
					{
						f=1;
						break;
					}
				}
				if(f) continue;
				for(int t=j;t<j+x;t++)
				{
					if(t1[t]!=a[i].s1[t-j]||t2[t]!=a[i].s2[t-j])
					{
						f=1;
						break;
					}
				}
				if(!f) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
