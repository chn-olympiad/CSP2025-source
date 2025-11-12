#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005];
struct str
{
	long long d,bh,cha,cha2,cha3,cha4,cha5;
}t[100005];
bool cmp(str x,str y)
{
	if(x.cha!=y.cha)
		return x.cha<y.cha;
	else
		return x.bh<y.bh;
}
bool cmp1(str x,str y)
{
	if(x.cha4!=y.cha4)
		return x.cha4<y.cha4;
	else
		return x.bh<y.bh;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--)
	{
		long long i,j,n,ans=0,a1=0,b1=0,c1=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i])
			{
				t[i].d=1;
				ans+=a[i];
				a1++;
				t[i].bh=i;
				if(a[i]-b[i]>=a[i]-c[i])
				{
					t[i].cha=a[i]-c[i];
					t[i].cha2=a[i]-b[i];
					t[i].cha3=2;
					t[i].cha5=3;
				}
				else
				{
					t[i].cha2=a[i]-c[i];
					t[i].cha=a[i]-b[i];
					t[i].cha3=3;
					t[i].cha5=2;
				}
			}
			else if(b[i]>=a[i]&&b[i]>=c[i])
			{
				t[i].d=2;
				ans+=b[i];
				b1++;
				if(b[i]-a[i]>=b[i]-c[i])
				{
					t[i].cha=b[i]-c[i];
					t[i].cha2=b[i]-a[i];
					t[i].cha3=1;
					t[i].cha5=3;
				}
				else
				{
					t[i].cha2=b[i]-c[i];
					t[i].cha=b[i]-a[i];
					t[i].cha3=3;
					t[i].cha5=1;
				}
			}
			else if(c[i]>=a[i]&&c[i]>=b[i])
			{
				t[i].d=3;
				ans+=c[i];
				c1++;
				if(c[i]-b[i]>=c[i]-a[i])
				{
					t[i].cha=c[i]-a[i];
					t[i].cha2=c[i]-b[i];
					t[i].cha3=2;
					t[i].cha5=1;
				}
				else
				{
					t[i].cha2=c[i]-a[i];
					t[i].cha=c[i]-b[i];
					t[i].cha3=1;
					t[i].cha5=2;
				}
			}
			cout<<t[i].cha<<" ";
			t[i].cha4=t[i].cha2-t[i].cha3;
		}
		cout<<endl;
		sort(t+1,t+n+1,cmp);
		long long duo=0;
		if(a1<=(n/2)&&b1<=(n/2)&&c1<=(n/2))
		{
			cout<<ans<<endl;
			continue;
		}
		else
		{
			if(a1>(n/2))
			{
				duo+=(a1-(n/2));
			}
			if(b1>(n/2))
			{
				duo+=(b1-(n/2));
			}
			if(c1>(n/2))
			{
				duo+=(c1-(n/2));
			}
			cout<<duo<<" ";
			sort(t+1,t+n+1,cmp1);
			for(j=1;j<=duo;j++)
			{
				ans-=t[i].cha;
				if(t[i].d==1)
				{
					a1--;
					if(t[i].cha5==1)
						a1++;
					if(t[i].cha5==2)
						b1++;
					if(t[i].cha5==3)
						c1++;
						
				}
				if(t[i].d==2)
				{
					b1--;
					if(t[i].cha5==1)
						a1++;
					if(t[i].cha5==2)
						b1++;
					if(t[i].cha5==3)
						c1++;
				}
				if(t[i].d==3)
				{
					c1--;
					if(t[i].cha5==1)
						a1++;
					if(t[i].cha5==2)
						b1++;
					if(t[i].cha5==3)
						c1++;
				}
			}
			cout<<ans<<endl;
			duo=0;
			if(a1>(n/2))
			{
				duo+=(a1-(n/2));
			}
			if(b1>(n/2))
			{
				duo+=(b1-(n/2));
			}
			if(c1>(n/2))
			{
				duo+=(c1-(n/2));
			}
			for(i=1;i<=duo;i++)
			{
				ans-=t[i].cha4;
			}
		}
		cout<<ans<<endl;
	}
}
