#include<bits/stdc++.h>
using namespace std;
int t,n,f,a[100005],b[100005],c[100005];
long long s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		s=0;
		for(int i=1;i<=100001;i++)
		{
			a[i]=b[i]=c[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0)
			{
				f=1;
			}
		}
		if(n==2)
		{
			int x,y,l,r,u,v;
            l=max(a[1],max(b[1],c[1])),r=min(a[1],min(b[1],c[1]));
            x=a[1]+b[1]+c[1]-l-r;
            u=max(a[2],max(b[2],c[2])),v=min(a[2],min(b[2],c[2]));
            y=a[2]+b[2]+c[2]-u-v;
            if((l==a[1]&&u==a[2])||(l==b[1]&&u==b[2])||(l==c[1]&&r==c[2]))
            {
	            s=max(l+y,x+u);
            }
            else
            {
	            s=l+u;
            }
            cout<<s;
            continue;
		}
		if(f==0)
		{
			sort(a+1,a+n+1,cmp);
	        for(int i=1;i<=n/2;i++)
	        {
	    	    s+=a[i];
		    }
		}
	    else
	    {
	    	for(int i=1;i<=n;i++)
		    {
			    s+=max(a[i],max(b[i],c[i]));
		    }
		}
		cout<<s<<endl;
	}
}
