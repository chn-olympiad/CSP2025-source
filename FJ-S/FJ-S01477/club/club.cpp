#include<bits/stdc++.h>
using namespace std;
long long n,A,B,C,cost1[114514],cost2[114514],cost3[114514],ans=0,t;
struct stu
{
	long long a,b,c;
}x[114514];
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		A=B=C=0;
		memset(cost1,11451419,sizeof(cost1));
   	 	memset(cost2,11451419,sizeof(cost2));
   		memset(cost3,11451419,sizeof(cost3));
   		for(long long i=1;i<=114510;i++)
   		x[i].a=x[i].b=x[i].c=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c)
			{
				A++;
				ans+=x[i].a;
//				cout<<ans<<endl;
			} 
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c)
			{
				B++;
				ans+=x[i].b;
//				cout<<ans<<endl;
			}
			else if(x[i].c>=x[i].a&&x[i].c>=x[i].b)
			{
				C++;
				ans+=x[i].c;
//				cout<<ans<<endl;
			}
		}
//	cout<<A<<" "<<B<<" "<<C<<endl;
		if(A<=n/2&&B<=n/2&&C<=n/2)
		{
			cout<<ans<<endl;
		}
		if(A>n/2)
		{
			for(long long i=1;i<=n;i++)
			{
				if(x[i].a>=x[i].b&&x[i].a>=x[i].b)
				cost1[i]=min(x[i].a-x[i].b,x[i].a-x[i].c);
			}
			sort(cost1+1,cost1+n+1);
			long long duoyu=A-n/2;
			for(long long i=1;i<=duoyu;i++)
			ans-=cost1[i];
			cout<<ans<<endl;
		}
		if(B>n/2)
		{
			for(long long i=1;i<=n;i++)
			{
				if(x[i].b>=x[i].a&&x[i].b>=x[i].c)
				cost2[i]=min(x[i].b-x[i].a,x[i].b-x[i].c);
			}
			sort(cost2+1,cost2+n+1);
			long long duoyu=B-n/2;
			for(long long i=1;i<=duoyu;i++)
			ans-=cost2[i];
			cout<<ans<<endl;
		}
		if(C>n/2)
		{
			for(long long i=1;i<=n;i++)
			{
				if(x[i].c>=x[i].a&&x[i].c>=x[i].b)
				cost3[i]=min(x[i].c-x[i].a,x[i].c-x[i].b);
			}
			sort(cost3+1,cost3+n+1);
			long long duoyu=C-n/2;
			for(long long i=1;i<=duoyu;i++)
			ans-=cost3[i];
			cout<<ans<<endl;
		}	
	}
	return 0;
}
/*
2
6
0 15 15
10 0 6
10 0 14
18 12 8
4 18 5
8 0 10
6
0 8 5
16 10 8
12 14 15
15 0 12
16 11 10
0 14 0
*/
