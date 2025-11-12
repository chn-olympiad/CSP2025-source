//[10,25]
#include <bits/stdc++.h>
using namespace std;
string u[10005],u2[10005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>u2[i];
	}
	while(q--)
	{
		int ans = 0;
		string qq,q1,q2;
		cin>>q1>>q2;
		qq = q1;
		for(int i=1;i<=n;i++)
		{
			for(int st=0;st<q1.size();st++)
			{

				if(st+u[i].size()>q1.size()) break;
				int ed = st+u[i].size()-1;
				bool flag = 0;
				for(int j=st;j<=ed;j++)
				{
					if(qq[j]!=u[i][j-st])
					{
						flag = 1;
					}
				}
				if(flag) continue;
				for(int j=st;j<=ed;j++)
				{
					qq[j] = u2[i][j-st];
				}
				if(qq==q2) ans++;
				qq = q1;
			}
		}
		printf("%d\n",ans);
	}
}