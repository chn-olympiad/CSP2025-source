#include<bits/stdc++.h>
using namespace std;
const int N=114514;
string s[N<<1][3],t1,t2,t3;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q)
	{
		q--;
		cin>>t1>>t2;
		int len=t1.size(),l=-1,r=-1;
		for(int i=0;i<len;i++)
		{
			if(t1[i]!=t2[i])
			{
				if(l==-1)
				{
					l=i;
					r=i;
				}
				else
				  r=i;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i][1].size()<r-l+1)
			{
				continue;
			}
			for(int j=r-s[i][1].size()+1;j<=l;j++)
			{
				t3=t1;
				int f=1;
				for(int k=j;k<=j+s[i][1].size()-1;k++)
				{
					if(t3[k]!=s[i][1][k-j])
					{
						f=0;
						break;
					}
					t3[k]=s[i][2][k-j];
				}
				if(f&&t3==t2)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
 } //我要上人类迷惑行为大赏！*114514
