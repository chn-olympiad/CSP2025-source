#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct jcj{
	int a,b,c,f;
}people[1000005]; 
int cmpa(jcj a,jcj b)
{
	return a.a>b.a; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club,out","w",stdout);
	cin>>T;
	while(T--)
	{
		int ans=0;
		bool f1=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>people[i].a>>people[i].b>>people[i].c;    
			if(people[i].b!=0||people[i].c!=0)f1=1;
		}	
		if(f1==0)
		{
			sort(people+1,people+1+n,cmpa);
			for(int i=1;i<=n/2;i++)
			{ 
				ans+=people[i].a;
			}
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=n;i++)
			{
				int a=people[i].a;
				int b=people[i].b;
				int c=people[i].c;
				if(a>=c&&a>=b)
				{
					ans+=a;
				} 
				if(b>=a&&b>=c)
				{
					ans+=b;
				}
				if(c>=a&&c>=b)
				{
					ans+=c;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
 } 
