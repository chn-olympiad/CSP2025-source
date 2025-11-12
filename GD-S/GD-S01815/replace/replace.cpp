#include<bits/stdc++.h>
#define ll long long
const int N=3e6+10;
const int inf=0x3f3f3f3f;
using namespace std;
int n,m;
string a[N],b[N];
char x[N],y[N];
int vis[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(m--)
	{
		scanf("%s%s",x,y);
		string h=x; 
		int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<strlen(x);j++)
				{
					if(a[i][0]==x[j])
					{
						int flag=0;
						for(int k=j;k<a[i].size();k++)
						{
							if(a[i][k-j]!=x[k])
							{
								flag=1;
								break;
							}
						}
						if(!flag)
						{
							string g,u;
							for(int k=0;k<j;k++)u+=x[k];
							for(int k=j+a[i].size();k<strlen(x);k++)g+=x[k];
							string f=u+b[i]+g;
							if(f==y)
							{
								ans++;
							}	
						}
					}
				}
			}
			printf("%d\n",ans);
		
	}
	return 0;
}
