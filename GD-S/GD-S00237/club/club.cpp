#include<bits/stdc++.h>
using namespace std;
const int N=100002;

struct pers
{
	int a,b,c;
};

bool cmp(pers x,pers y)
{
	return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
}

pers apart[N];

int main()
{
	int T,n,ans=0;
	bool flag=true;
	int A=0,B=0,C=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;A=0;B=0;C=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>apart[i].a>>apart[i].b>>apart[i].c;
			if(flag && apart[i].b==0 && apart[i].c==0) continue;
			else flag=false;
		}
		sort(apart,apart+n,cmp);
//		for(int i=0;i<n;i++) cout<<apart[i].a<<" "<<apart[i].b<<" "<<apart[i].c<<endl;
//		cout<<endl;
		if(flag)
		{
			for(int i=0;i<n;i++)
			{
				ans+=apart[i].a;
				A++;
				if(A==n/2) break;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(apart[i].a>apart[i].b && apart[i].a>apart[i].c)
			{
				if(A==n/2)
				{
					if(apart[i].b>apart[i].c)
					{
						ans+=apart[i].b;
						B++;
					}
					else
					{
						ans+=apart[i].c;
						C++;
					}
				}
				else
				{
					ans+=apart[i].a;
					A++;
				}
			}
			else if(apart[i].b>apart[i].a && apart[i].b>apart[i].c)
			{
				if(B==n/2)
				{
					if(apart[i].a>apart[i].c)
					{
						ans+=apart[i].a;
						A++;
					}
					else
					{
						ans+=apart[i].c;
						C++;
					}
				}
				else
				{
					ans+=apart[i].b;
					B++;
				}
			}
			else if(apart[i].c>apart[i].b && apart[i].c>apart[i].a)
			{
				if(C==n/2)
				{
					if(apart[i].b>apart[i].a)
					{
						ans+=apart[i].b;
						B++;
					}
					else
					{
						ans+=apart[i].a;
						A++;
					}
				}
				else
				{
					ans+=apart[i].c;
					C++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
