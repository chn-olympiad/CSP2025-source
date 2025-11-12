//GZ-S00360 贵阳市第十八中学 罗嘉龙
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
struct Na
{
	int a,b,c,n,m1,m2,m3,ans1,ans2,ans3,cz1,cz2;
}q[N];

int cmp(Na x,Na y)
{
		return x.cz1<y.cz1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n,rn;
		cin>>n;
		rn=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>q[i].a>>q[i].b>>q[i].c;
			q[i].n=i;
			if(q[i].a>q[i].b&&q[i].a>q[i].c)
			{
				q[i].m1=1;
				q[i].ans1=q[i].a;
				if(q[i].b>q[i].c)q[i].m2=2,q[i].m3=3;
				else q[i].m2=3,q[i].m3=2;
				q[i].ans2=max(q[i].b,q[i].c);
				q[i].ans3=min(q[i].b,q[i].c);
				q[i].cz1=q[i].ans1-q[i].ans2;
				q[i].cz2=q[i].ans2-q[i].ans3;

			}
			else if(q[i].b>q[i].a&&q[i].b>q[i].c)
			{
				q[i].m1=2;
				q[i].ans1=q[i].b;
				if(q[i].a>q[i].c)q[i].m2=1,q[i].m3=3;
				else q[i].m2=3,q[i].m3=1;
				q[i].ans2=max(q[i].a,q[i].c);
				q[i].ans3=min(q[i].a,q[i].c);
				q[i].cz1=q[i].ans1-q[i].ans2;
				q[i].cz2=q[i].ans2-q[i].ans3;
			}
			else
			{
				q[i].m1=3;
				q[i].ans1=q[i].c;
				if(q[i].a>q[i].b)q[i].m2=1,q[i].m3=2;
				else q[i].m2=2,q[i].m3=1;
				q[i].ans2=max(q[i].b,q[i].a);
				q[i].ans3=min(q[i].b,q[i].a);
				q[i].cz1=q[i].ans1-q[i].ans2;
				q[i].cz2=q[i].ans2-q[i].ans3;
			}
		}
		int s1=0,s2=0,s3=0,z=0;
		for(int i=1;i<=n;i++)
		{
			z+=q[i].ans1;
			if(q[i].m1==1)s1++;
			else if(q[i].m1==2)s2++;
			else s3++;
		}
		if(s3<=rn&&s2<rn&&s1<=rn)
		{
			cout<<z<<endl;
			continue;
		}
		else if(s1>=rn)
		{
			sort(q+1,q+n+1,cmp);
			for(int i=1;;i++)
			{
				s1--;
				if(q[i].m1==1)
					z=z-q[i].ans1+q[i].ans2;
				else s1++;
				if(s1==rn)break;
			}
			cout<<z<<endl;
			continue;
		}
		else if(s2>=rn)
		{
			sort(q+1,q+n+1,cmp);
			for(int i=1;;i++)
			{
				s2--;
				if(q[i].m1==2)
					z=z-q[i].ans1+q[i].ans2;
				else s2++;
				if(s2==rn)break;
			}
			cout<<z<<endl;
			continue;
		}
		else if(s3>=rn)
		{
			sort(q+1,q+n+1,cmp);
			for(int i=1;;i++)
			{
				s3--;
				if(q[i].m1==3)
					z=z-q[i].ans1+q[i].ans2;
				else s3++;
				if(s3==rn)break;
			}
			cout<<z<<endl;
			continue;
		}
	}
	return 0;
}
