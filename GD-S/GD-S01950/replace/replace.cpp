#include<bits/stdc++.h>
using namespace std;
int n,q;
struct str{
	string s1,s2;
}s[100050];
int	main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int t=0;t<t1.size();t++)
		{
			for(int k=1;k<=n;k++)
			{
				int w=s[k].s1.size();
				if(t+w>t1.size())
				{
					continue;
				}
				bool key=0;
				for(int j=0;j<w;j++)
				{
					if(t1[t+j]!=s[k].s1[j])
					{
						key=1;
						break;
					}
				}
				if(key==0)
				{
					string temp=t1;
					for(int j=0;j<w;j++)
					{
						temp[t+j]=s[k].s2[j];
					}
					if(temp==t2)
					{
						ans++;	
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
