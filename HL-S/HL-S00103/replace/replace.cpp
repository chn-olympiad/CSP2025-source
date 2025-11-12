#include<bits/stdc++.h>
using namespace std;
char a[105][2][105];
char f[205],t[205];
//string aa[200005][2];
//string ff,tt;
//int ap[200005][2];
//int av[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n<=110)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=q;i++)
		{
			int ans=0;
			cin>>f>>t;
			for(int j=1;j<=n;j++)
			{
				if(strlen(f)>=strlen(a[j][1]))
				{
					for(int k=0;k<=strlen(f)-strlen(a[j][1]);k++)
					{
						//cout<<0<<' '<<k<<' '<<k+strlen(a[j][2])-1<<' '<<k+strlen(a[j][2])<<' '<<strlen(f)-1<<' '<<j<<endl;
						int p=1;
						for(int u=0;u<k;u++)
						{
							if(f[u]!=t[u])
							{
								p=0;
								break;
							}
						}
						if(!p)
						{
							continue;
						}
						for(int u=k;u<=k+strlen(a[j][2])-1;u++)
						{
							if(!((f[u]==a[j][1][u-k])&&(t[u]==a[j][2][u-k])))
							{
								p=0;
								break;
							}
						}
						if(!p)
						{
							continue;
						}
						for(int u=k+strlen(a[j][2]);u<strlen(f);u++)
						{
							if(f[u]!=t[u])
							{
								p=0;
								break;
							}
						}
						if(!p)
						{
							continue;
						}
						if(p==1)
						{
							ans++;
						}
					}
				}
				
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	/*for(int i=1;i<=n;i++)
	{
		cin>>aa[i][1]>>aa[i][2];
		int vis=0;
		for(int j=0;j<aa[i][1].size();j++)
		{
			if(aa[i][1][j]=='b')
			{
				vis=1;
				continue;
			}
			if(!vis)
			{
				ap[i][1]++;
			}
			if(vis)
			{
				av[i][1]++;
			}
		}
		vis=0;
		for(int j=0;j<aa[i][2].size();j++)
		{
			if(aa[i][2][j]=='b')
			{
				vis=1;
				continue;
			}
			if(!vis)
			{
				ap[i][2]++;
			}
			if(vis)
			{
				av[i][2]++;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ff>>tt;
		int pref=0,verf=0;
		int pret=0,vert=0;
		int ans=0;
		for(int j=0;j<ff.size();j++)
		{
			int vis=0;
				if(ff[j]=='b')
				{
					vis=1;
					continue;
				}
				if(!vis)
				{
					pref++;
				}
				if(vis)
				{
					verf++;
				}
		
		}
		for(int j=0;j<tt.size();j++)
		{
			int vis=0;
				if(tt[j]=='b')
				{
					vis=1;
					continue;
				}
				if(!vis)
				{
					pret++;
				}
				if(vis)
				{
					vert++;
				}
			
		}
		cout<<pref<<' '<<verf<<' '<<pret<<' '<<vert<<endl;
	}*/
}
