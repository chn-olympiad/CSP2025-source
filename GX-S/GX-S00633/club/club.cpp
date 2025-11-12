#include<bits/stdc++.h>
using namespace std;
long long maxn=-1;
struct cb
{
	long long a,b,c;
}x[100001];
void px(int n,int i,long long ans,int k,int as,int bs,int cs)
{
	if(i>n) return ;
	if(k==1) 
	{
		if(as>n/2) return ;
		ans+=x[i].a;
	}
    if(k==2) 
	{
		if(bs>n/2) return ;
		ans+=x[i].b;
	}
	if(k==3) 
	{
		if(cs>n/2) return ;
		ans+=x[i].c;
	}
	maxn=max(maxn,ans);
	px(n,i+1,ans,1,as+1,bs,cs);
	px(n,i+1,ans,2,as,bs+1,cs);
	px(n,i+1,ans,3,as,bs,cs+1);
}
bool cmp(cb m,cb n)
{
	return m.a>n.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
		
		long long n;
		cin>>n;
		bool bf=true,cf=true;
		for(int i=1;i<=n;i++)
		{
			long long a1,b1,c1;
			cin>>a1>>b1>>c1;
			if(b1!=0) bf=false;
			if(c1!=0) cf=false;

			x[i].a=a1;
			x[i].b=b1;
			x[i].c=c1;
		}
		if(bf==true&&cf==true)
		{
			sort(x+1,x+1+n,cmp);
			long long ans=0;
			for(int j=1;j<=n/2;j++)
			{
				ans+=x[j].a;
			}
			cout<<ans<<endl;
			continue;
		}
		else if(cf==true&&bf==false)
		{
			long long ans=0;
			for(int j=1;j<=n;j++)
			{
				ans+=x[j].a+x[j].b;
			}
			cout<<ans<<endl;
			continue;
		}
		px(n,1,0,1,1,0,0);
		px(n,1,0,2,0,1,0);
		px(n,1,0,3,0,0,1);
		cout<<maxn<<endl;
		maxn=-1;
	}
    return 0;
}
