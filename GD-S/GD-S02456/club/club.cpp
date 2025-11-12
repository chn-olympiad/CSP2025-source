#include<bits/stdc++.h>
using namespace std;
long long t,n,b1[100005],b2[100005],b3[1000005],s,rs[5];
struct aa{
	long long  a,b,c,sx,cj,cx,hj,hx;
}a[100005];
bool cmp(long long  x,long long  y)
{
	if(a[x].cj==a[y].cj)
	{
		if(rs[a[x].cx]==rs[a[y].cx])
		{
			return a[x].hj>a[y].hj;
		}
		return rs[a[x].cx]>rs[a[y].cx];
	}
	return a[x].cj>a[y].cj;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		s=0;
		rs[1]=0;
		rs[2]=0;
		rs[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].a>=a[i].c&&a[i].a>=a[i].b)
			{
				a[i].sx=1;
				rs[1]++;
				b1[rs[1]]=i;
				if(a[i].b>=a[i].c)
				{
					a[i].cj=a[i].a-a[i].b;
					a[i].hj=a[i].b-a[i].c;
					a[i].cx=2;
					a[i].hx=3;
				}
				else
				{
					a[i].cj=a[i].a-a[i].c;
					a[i].hj=a[i].c-a[i].b;
					a[i].cx=3;
					a[i].hx=2;
				}
				s+=a[i].a;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				a[i].sx=2;
				rs[2]++;
				b2[rs[2]]=i;
				if(a[i].a>=a[i].c)
				{
					a[i].cj=a[i].b-a[i].a;
					a[i].hj=a[i].a-a[i].c;
					a[i].cx=1;
					a[i].hx=3;
				}
				else
				{
					a[i].cj=a[i].b-a[i].c;
					a[i].hj=a[i].c-a[i].a;
					a[i].cx=3;
					a[i].hx=1;
				}
				s+=a[i].b;
			}
			else
			{
				a[i].sx=3;
				rs[3]++;
				b3[rs[3]]=i;
				if(a[i].a>=a[i].b)
				{
					a[i].cj=a[i].c-a[i].a;
					a[i].hj=a[i].a-a[i].b;
					a[i].cx=1;
					a[i].hx=2;
				}
				else
				{
					a[i].cj=a[i].c-a[i].b;
					a[i].hj=a[i].b-a[i].a;
					a[i].cx=2;
					a[i].hx=1;
				}
				s+=a[i].c;
			}
//			cout<<a[i].sx<<" "<<a[i].cx<<" "<<a[i].cj<<" "<<a[i].hx<<" "<<a[i].hj<<endl;
		}
		while(rs[1]>n/2||rs[2]>n/2||rs[3]>n/2)
		{
//			cout<<rs[1]<<" "<<rs[2]<<" "<<rs[3]<<endl<<endl;
			if(rs[1]>n/2)
			{
				sort(b1+1,b1+rs[1]+1,cmp);
				for(int i=rs[1];i>=n/2+1;i--)
				{
					rs[a[b1[i]].cx]++;
					if(a[b1[i]].cx==2)
					{
						b2[rs[a[b1[i]].cx]]=b1[i];
					}
					else
					{
						b3[rs[a[b1[i]].cx]]=b1[i];
					}
					s-=a[b1[i]].cj;
					a[b1[i]].sx=a[b1[i]].cx;
					a[b1[i]].cj=a[b1[i]].hj;
					a[b1[i]].cx=a[b1[i]].hx;
					a[b1[i]].hj=0;
				}
				rs[1]=n/2;
			}
			else if(rs[2]>n/2)
			{
				sort(b2+1,b2+rs[2]+1,cmp);
				for(int i=rs[2];i>=n/2+1;i--)
				{
					rs[a[b2[i]].cx]++;
					if(a[b2[i]].cx==1)
					{
						b1[rs[a[b2[i]].cx]]=b2[i];
					}
					else
					{
						b3[rs[a[b2[i]].cx]]=b2[i];
					}
					s-=a[b2[i]].cj;
					a[b2[i]].sx=a[b2[i]].cx;
					a[b2[i]].cj=a[b2[i]].hj;
					a[b2[i]].cx=a[b2[i]].hx;
					a[b2[i]].hj=0;
				}
				rs[2]=n/2;
			}
			else if(rs[3]>n/2)
			{
				sort(b3+1,b3+rs[3]+1,cmp);
				for(int i=rs[3];i>=n/2+1;i--)
				{
					rs[a[b3[i]].cx]++;
					if(a[b3[i]].cx==1)
					{
						b1[rs[a[b3[i]].cx]]=b3[i];
					}
					else
					{
						b2[rs[a[b3[i]].cx]]=b3[i];
					}
					s-=a[b3[i]].cj;
					a[b3[i]].sx=a[b3[i]].cx;
					a[b3[i]].cj=a[b3[i]].hj;
					a[b3[i]].cx=a[b3[i]].hx;
					a[b3[i]].hj=0;
				}
				rs[3]=n/2;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
