#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int a1,b1,c1;
long long ans;
struct mumber
{
	int a,b,c,d;
	int ab;
	bool fa=0,fb=0,fc=0;
}p[N];
bool cmp1(mumber x,mumber y){
	return x.d<y.d;
}
bool cmp2(mumber x,mumber y){
	if(x.ab>y.ab) return x.ab>y.ab;
	if(x.ab==y.ab) return x.a>y.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%d",&n);
		a1=0,b1=0,c1=0;
		int x=n/2;
		int n1,n2;
		n1=n;
		n2=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
			p[i].d=max(max(p[i].a,p[i].b),p[i].c);
			if(p[i].b==0)n1--;
			if(p[i].c==0)n2--;
			p[i].ab=max(p[i].a,p[i].b)-min(p[i].a,p[i].b);
		}
		if(n==2)
		{
			int ans[10]={0};
			ans[1]=p[1].a+p[2].b;
			ans[2]=p[1].a+p[2].c;
			ans[3]=p[1].b+p[2].c;
			ans[4]=p[1].b+p[2].a;
			ans[5]=p[1].c+p[2].b;
			ans[6]=p[1].c+p[2].a;
			sort(ans+1,ans+7);
			cout<<ans[6]<<endl;	
		}
		else if(n1==0&&n2==0){
			sort(p+1,p+1+n,cmp1);
			for(int i=1;i<=x;i++)
			{
				ans+=p[i].d;
			}
			cout<<ans<<endl;
		}
		else if(n2==0){
			int mn=0;
			sort(p+1,p+1+n,cmp2);
			for(int i=1;;i++)
			{
				mn=i;
				if(p[i].a>p[i].b){
					ans+=p[i].a;
					a1++;
				}
				else 
				{
					ans+=p[i].b;
					b1++;
				}
				if(a1==x||b1==x)break;
			}
			if(a1==x)
			{
				for(int i=mn+1;i<=n;i++)
				{
					ans+=p[i].b;
				}
				
			}
			if(b1==x)
			{
				for(int i=mn+1;i<=n;i++)
				{
					ans+=p[i].a;
				}
				
			}
			cout<<ans<<endl;
		}
		else {
			for(int i=1;i<=n;i++)
			{
				ans+=p[i].d;
				if(p[i].a==p[i].d){
					a1++;
					p[i].fa=1;	
				}
				if(p[i].b==p[i].d){
					b1++;
					p[i].fb=1;	
				}
				if(p[i].c==p[i].d){
					c1++;
					p[i].fc=1;
				}
			}
			
			while(a1>x||b1>x||c1>x)
			{
				if(a1>x)
				{
					int i=0;
					while(a1>x)
					{
						i++;
						if(p[i].fa==0)continue;
						p[i].fa=0;
						a1--;
						ans-=p[i].a;
						if(p[i].b>p[i].c)
						{
							ans+=p[i].b;
							p[i].fb=1;
							b1++;
						}
						if(p[i].b<p[i].c)
						{
							ans+=p[i].c;
							p[i].fc=1;
							c1++;
						}
					}
				}
				if(b1>x)
				{
					int i=0;
					while(b1>x)
					{
						i++;
						if(p[i].fb==0)continue;
						p[i].fb=0;
						b1--;
						ans-=p[i].b;
						if(p[i].a>p[i].c)
						{
							ans+=p[i].a;
							p[i].fa=1;
							a1++;
						}
						if(p[i].a<p[i].c)
						{
							ans+=p[i].c;
							p[i].fc=1;
							c1++;
						}
					}
				}
				if(c1>x)
				{
					int i=0;
					while(c1>x)
					{
						i++;
						if(p[i].fc==0)continue;
						p[i].fc=0;
						c1--;
						ans-=p[i].c;
						if(p[i].a>p[i].b)
						{
							ans+=p[i].a;
							p[i].fa=1;
							a1++;
						}
						if(p[i].a<p[i].b)
						{
							ans+=p[i].b;
							p[i].fb=1;
							b1++;
						}
					}
				}
				
			}
			cout<<ans<<endl;
		}
		
		
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
}
