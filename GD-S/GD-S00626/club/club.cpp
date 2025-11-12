#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,o,s1,s2,l;
struct student
{
	int a,b,c;
}s[100005];
int p,q,r;
long long ans;
bool cmp1(student a1,student a2)
{
	s1=max(a1.b,a1.c);
	s2=max(a2.b,a2.c);
	return s1>s2;
}
bool cmp2(student a1,student a2)
{
	s1=max(a1.a,a1.c);
	s2=max(a2.a,a2.c);
	return s1>s2;
}
bool cmp3(student a1,student a2)
{
	s1=max(a1.a,a1.b);
	s2=max(a2.b,a2.a);
	return s1>s2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		p=0;
		q=0;
		r=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			o=max(s[i].a,max(s[i].b,s[i].c));
			if(o==s[i].a)
			{
				++p;
				s[i].b-=o;
				s[i].c-=o;
			}
			else if(o==s[i].b)
			{
				++q;
				s[i].a-=o;
				s[i].c-=o;
			}
			else  
			{
				++r;
				s[i].a-=o;
				s[i].b-=o;
			}
			ans+=o;
		}
		l=0;
		if(p>(n/2))
		{
			sort(s+1,s+1+n,cmp1);
			while(max(s[l].b,s[l].c)>0) ++l;
			for(int kk=l;kk<=l+p-(n/2);kk++)
			{
				ans+=max(s[kk].b,s[kk].c);
			}
		}
		else if(q>(n/2))
		{
			sort(s+1,s+1+n,cmp2);
			while(max(s[l].a,s[l].c)>0) 
			{
				++l;
			}
			for(int kk=l;kk<=l+q-(n/2);kk++)
			{
				ans+=max(s[kk].a,s[kk].c);
			}
		}
		else if(r>(n/2))
		{
			sort(s+1,s+1+n,cmp3);
			while(max(s[l].b,s[l].a)>0) ++l;
			for(int kk=l;kk<=l+r-(n/2);kk++)
			{
				ans+=max(s[kk].b,s[kk].a);
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
} 
