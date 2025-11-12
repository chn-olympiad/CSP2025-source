#include<bits/stdc++.h>
using namespace std;
int k;
struct Node{
	int a,b,c,d,q,w,e,u;
}p[1000005];
bool cmp1(Node x,Node y)
{
	return x.u>y.u;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>k;
    for(int i=1;i<=k;i++)
    {
		int x=0,y=0,z=0,n;
		long long tot=0;
   		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>p[j].a>>p[j].b>>p[j].c;
		    p[j].q=p[j].a-p[j].b+p[j].a-p[j].c;
		    p[j].w=p[j].b-p[j].a+p[j].b-p[j].c;
		    p[j].e=p[j].c-p[j].a+p[j].c-p[j].b;
		    if(p[j].q>=p[j].w&&p[j].q>=p[j].e)
		    p[j].d=1;
		    if(p[j].w>=p[j].q&&p[j].w>=p[j].e)
		    p[j].d=2;
		    if(p[j].e>=p[j].q&&p[j].e>=p[j].w)
		    p[j].d=3;
		    p[j].u=max(p[j].q,max(p[j].w,p[j].e));
        }
        sort(p+1,p+n+1,cmp1);
        for(int j=1;j<=n/2;j++)
        {
			if(p[j].d==1)
			tot+=p[j].a,x++;
			if(p[j].d==2)
			tot+=p[j].b,y++;
			if(p[j].d==3)
			tot+=p[j].c,z++;
		}
		for(int j=n/2+1;j<=n;j++)
		{
			if(p[j].d==1)
			{
				if(x<n/2)
				tot+=p[j].a,x++;
				else
				{
		            tot+=max(p[j].b,p[j].c);
			    }
			}
			if(p[j].d==2)
			{
				if(y<n/2)
				tot+=p[j].b,y++;
				else
				{
		            tot+=max(p[j].a,p[j].c);
			    }
			}
			if(p[j].d==3)
			{
				if(z<n/2)
				tot+=p[j].c,z++;
				else
				{
		            tot+=max(p[j].a,p[j].b);
			    }
			}
		}
		cout<<tot<<" !";
	}
    return 0;
}
