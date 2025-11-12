#include<bits/stdc++.h>
using namespace std;
int n,t;
int as,bs,cs,ans;
struct ss
{
	int a,b,c;
	
}a[100001];
bool cmp(ss a,ss b)
{
	if(a.a!=b.a) 
		return a.a>b.a;
	else
		if(a.b!=b.b)
			return a.b>b.b;
		else
		//	if(a.c!=b.c)
				return a.c>b.c;
	
	
	
}
int main()
{
	
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(int i=1;i<=n;i++)
				cin>>a[i].a>>a[i].b>>a[i].c;
			sort(a+1,a+1+n,cmp);
			
			for(int i=1;i<=n;i++)
			{	
				if(a[i].a>=a[i].b && a[i].a>=a[i].c && a[0].a<n/2 && a[i].a!=0)
				{	
						a[0].a++;
						ans=ans+a[i].a;
						continue;
					
				} 
				if(a[i].b>=a[i].a && a[i].b>=a[i].c && a[0].b<n/2 && a[i].b!=0)
				{
						a[0].b++;
						ans=ans+a[i].b;
						continue;
				}	
				if(a[i].c>=a[i].b && a[i].c>=a[i].a && a[0].c<n/2 && a[i].c!=0)
				{
						a[0].c++;
						ans=ans+a[i].c;
						continue;
				}
				
				
				
				
			}
			/*for(int i=0;i<=n;i++)
				cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<endl;*/
			cout<<ans<<endl;
			ans=0;
			a[0].a=0;
			a[0].b=0;
			a[0].c=0;
		}
		
		
		return 0;
}
