#include<bits/stdc++.h>
using namespace std;
int t,aa=0,ab=0,ac=0;
struct node{
	long long a,b,c;
}s[100050];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	cin>>t;
	long long n,ans=0;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			int king=-1,p;
			if(king<s[i].a)
			{
				king=s[i].a;
				if(aa<n/2) p=1;
				if(king<s[i].b)
				{
					king=s[i].b;
					if(aa<n/2) p=2;
					if(king<s[i].c)
					{
						king=s[i].c;if(ac<n/2) p=3;
					}
				}
				else
				{
					if(king<s[i].c)
					{
						king=s[i].c;if(ac<n/2) p=3;
					}
				}
			}
			cout<<p<<endl;
			if(p==1) {
			  ans+=s[i].a,aa+=1;	
			}
			else if(p==2) ans+=s[i].b,ab+=1;
			else ans+=s[i].c,ac+=1;
		}
		cout<<ans<<endl;
		ans=0,aa=0,ab=0,ac=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
