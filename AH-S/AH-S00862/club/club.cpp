#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
}x[500005];
bool cmp(node x,node y)
{
	if(x.a==y.a)
	{
		
		if(x.b==y.b)
		{
			return x.c>y.c;
		}
		return x.b>y.b;
	}
	return x.a>y.a;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int aa=0,bb=0,cc=0,aaa=0,ccc=0,bbb=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
		}
		sort(x+1,x+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c)
			{
				if(aaa<(n>>1))
				{
					aaa++;
					aa+=x[i].a;
				}
				else
				{
					if(x[i].b>=x[i].c)
					{
						if(bbb<(n>>1))
						{
							bbb++;
							bb+=x[i].b;
						}
						else
						{
							if(ccc<(n>>1))
							{
								ccc++;
								cc+=x[i].c;
							}
						}
					}
				}
			}
			else if(x[i].a>=x[i].b&&x[i].a>=x[i].c)
			{
				if(aaa<(n>>1))
				{
					aaa++;
					aa+=x[i].a;
				}
				else
				{
					if(x[i].c>=x[i].b)
					{
						if(ccc<(n>>1))
						{
							ccc++;
							cc+=x[i].c;
						}
						elseemploy
						{
							if(bbb<(n>>1))
							{
								bbb++;
								bb+=x[i].b;
							}
						}
					}
				}
			}
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c)
			{
				if(bbb<(n>>1))
				{
					bbb++;
					bb+=x[i].b;
				}
				else
				{
					if(x[i].c>=x[i].a)
					{
						if(ccc<(n>>1))
						{
							ccc++;
							cc+=x[i].c;
						}
						else
						{
							if(aaa<(n>>1))
							{
								aaa++;
								aa+=x[i].a;
							}
						}
					}
				}
			}
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c)
			{
				if(bbb<(n>>1))
				{
					bbb++;
					bb+=x[i].b;
				}
				else
				{
					if(x[i].a>=x[i].c)
					{
						if(aaa<(n>>1))
						{
							aaa++;
							aa+=x[i].a;
						}
						else
						{
							if(ccc<(n>>1))
							{
								ccc++;
								cc+=x[i].c;
							}
						}
					}
				}
			}
			
			else if(x[i].c>=x[i].a&&x[i].c>=x[i].b)
			{
				if(ccc<(n>>1))
				{
					ccc++;
					cc+=x[i].c;
				}
				else
				{
					if(x[i].a>=x[i].b)
					{
						if(aaa<(n>>1))
						{
							aaa++;
							aa+=x[i].a;
						}
						else
						{
							if(bbb<(n>>1))
							{
								bbb++;
								bb+=x[i].b;
							}
						}
					}
				}
			}
			else if(x[i].c>=x[i].a&&x[i].c>=x[i].b)
			{
				if(ccc<(n>>1))
				{
					ccc++;
					cc+=x[i].c;
				}
				else
				{
					if(x[i].b>=x[i].a)
					{
						if(bbb<(n>>1))
						{
							bbb++;
							bb+=x[i].b;
						}
						else
						{
							if(aaa<(n>>1))
							{
								aaa++;
								aa+=x[i].a;
							}
						}
					}
				}
			}
		}
		cout<<(aa+bb+cc)<<'\n';
	}
	return 0;
}
