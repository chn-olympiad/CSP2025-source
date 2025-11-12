#include<bits/stdc++.h>
using namespace std;
int ans[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		vector<int> la,lb,lc;
		int n,na=0,nb=0,nc=0;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			int t=max(a,max(b,c));
			ans[i]+=t;
			if(t==a)
			{
				if(na<n/2)
				{
					na++;
					la.push_back(t-max(b,c));
				}
				else
				{
					sort(la.begin(),la.end());
					if(t>la[0])
					{
						ans[i]-=la[0];
						la[0]=t-max(b,c);
					}
					else ans[i]+=max(b,c)-t;
				}
			}
			if(t==b)
			{
				if(nb<n/2)
				{
					nb++;
					lb.push_back(t-max(a,c));
				}
				else
				{
					sort(lb.begin(),lb.end());
					if(t>lb[0])
					{
						ans[i]-=lb[0];
						lb[0]=t-max(a,c);
					}
					else ans[i]+=max(c,a)-t;
				}
			}
			if(t==c)
			{
				if(nc<n/2)
				{
					nc++;
					lc.push_back(t-max(b,a));
				}
				else
				{
					sort(lc.begin(),lc.end());
					if(t>lc[0])
					{
						ans[i]-=lc[0];
						lc[0]=t-max(b,a);
					}
					else ans[i]+=max(b,a)-t;
				}
			}
		}
	}
	for(int i=0;i<t;i++)
		printf("%d\n",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
