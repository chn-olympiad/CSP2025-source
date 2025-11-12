#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int T;
int n;
struct node{
	int a,b,c;
	int maxi;
	int cd;
	int maxnum;
	int cdnum;
	int cha;
}k[maxn];
struct nk
{
	int maxi;
    int val;
	int id;	
	bool operator< (const nk &a) const
	{
		return a.val>val; 
	}
};
priority_queue<nk> q;
int maxa,maxb,maxc;
void count(node l)
{
	if(l.maxi==1) maxa++;
	if(l.maxi==2) maxb++;
	if(l.maxi==3) maxc++; 
}
bool cmp(node a,node b)
{
	return a.cha>b.cha;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
	{
		memset(k,0,sizeof(k));
		cin>>n;
		maxa=maxb=maxc=0;
		for(int i=1;i<=n;i++)
		{
			cin>>k[i].a>>k[i].b>>k[i].c;
			if(k[i].a>=k[i].b&&k[i].a>=k[i].c)
			{
				k[i].maxi=1; k[i].maxnum=k[i].a;
				if(k[i].b>=k[i].c) 
				{
					k[i].cd=2; k[i].cdnum=k[i].b;
				}
				else
				{
					 k[i].cd=3; k[i].cdnum=k[i].c;
				}
				k[i].cha=k[i].maxnum-k[i].cdnum;
				continue;
			}
			if(k[i].b>=k[i].a&&k[i].b>=k[i].c)
			{
				k[i].maxi=2; k[i].maxnum=k[i].b;
				if(k[i].a>=k[i].c) 
				{
					k[i].cd=1; k[i].cdnum=k[i].a;
				}
				else
				{
					 k[i].cd=3; k[i].cdnum=k[i].c;
				}
				k[i].cha=k[i].maxnum-k[i].cdnum;
				continue;
			}
			if(k[i].c>=k[i].a&&k[i].c>=k[i].b)
			{
				k[i].maxi=3; k[i].maxnum=k[i].c;
				if(k[i].a>=k[i].b) 
				{
					k[i].cd=1; k[i].cdnum=k[i].a;
				}
				else
				{
					 k[i].cd=2; k[i].cdnum=k[i].b;
				}
				k[i].cha=k[i].maxnum-k[i].cdnum;
			}
		}
	    for(int i=1;i<=n;i++)
	    {
	    	 count(k[i]);
		}
	//	for(int i=1;i<=n;i++) cout<<k[i].cha<<" ";
		if(maxa>n/2||maxb>n/2||maxc>n/2)
		{
			sort(k+1,k+1+n,cmp);
			long long ans=0;
	//	    for(int i=1;i<=n;i++) cout<<k[i].cha;
		    if(maxa>n/2)
		    {
		    	int j=0;
		    	for(int i=1;i<=n;i++)
		    	{
		    		if(k[i].maxi==1)
		    		{
		    			if(j<n/2)
		    			{
		    				j++;
		    				ans+=k[i].maxnum;
						}
						else{
							ans+=k[i].cdnum;
						}
					}
					else{
						ans+=k[i].maxnum;
					}
				}
			}
			 else   if(maxb>n/2)
		    {
		    	int j=0;
		    	for(int i=1;i<=n;i++)
		    	{
		    		if(k[i].maxi==2)
		    		{
		    			if(j<n/2)
		    			{
		    				j++;
		    				ans+=k[i].maxnum;
						}
						else{
							ans+=k[i].cdnum;
						}
					}
					else{
						ans+=k[i].maxnum;
					}
				}
			}
			 else   if(maxc>n/2)
		    {
		    	int j=0;
		    	for(int i=1;i<=n;i++)
		    	{
		    		if(k[i].maxi==3)
		    		{
		    			if(j<n/2)
		    			{
		    				j++;
		    				ans+=k[i].maxnum;
						}
						else{
							ans+=k[i].cdnum;
						}
					}
					else{
						ans+=k[i].maxnum;
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=k[i].maxnum;
			}
			cout<<ans<<endl;
		}
	 } 
	return 0;
 } 
