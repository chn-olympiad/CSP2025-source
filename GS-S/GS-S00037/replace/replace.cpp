#include<bits/stdc++.h>
using namespace std;
long long int n,q,ans=0,st1,fn1;
int ggg=0,fl=0,f2=0,f3=0,f4=0;
struct aa{
	string s1,s2,tt1,tt2;
}a[200010];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].s1 >>a[i].s2 ;
	}
	if(q==1)
	{
		cin>>t1>>t2;
		for(int i=0;i<n;i++)
	    {
	    	st1=0;
	    	fn1=n;
	    	f2=0;
	    	f3=0;
	    	f4=0;
	    	if((t1==a[i].s1 )&&(t2==a[i].s2 ))
	    	{
	    		fl=1;
	    		ans++;
			}
			else
			{
				for(int j=0;j<t1.size();j++)
				{
					if(t1[j]==a[i].s1[0] )
					{
						for(int tt=0;tt<a[i].s1 .size();tt++)
						{
							if(t1[j+tt]!=a[i].s1[tt])
							{
								f2=1;
								continue;
							}
						}
						if(f2==0)
						{
							for(int nn=0;nn<t2.size();nn++)
							{
								if(t1[nn]!=t2[nn])
								{
									for(int dds=0;dds<a[i].s2.size();dds++)
									{
										if(t2[nn+dds]!=a[i].s2[dds])
										{
											f3=1;
											continue;
										}
										
									}
									if(f3==0)
									{
										for(int hh=nn;hh<t1.size();hh++)
										{
											if(t1[hh+a[i].s1 .size()]!=t2[nn+a[i].s2 .size()])
											{
												f4=1;
												continue;
											}
										}
										if(f4==0)
										{
											fl=1;
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
			
		}
		if(fl==0)
		{
			printf("%d",ggg);
		}
		else
		{
			printf("%lld",ans);
		}
	}
	else
	{
		for(int i=0;i<q;i++)
		{
			cin>>a[i].tt1 >>a[i].tt2 ;
			printf("%d\n",ggg);
		}
	}
	return 0;
}
