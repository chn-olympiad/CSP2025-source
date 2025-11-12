#include<bits/stdc++.h>
using namespace std;
struct stu
{
	long long a,b,c,op,cha;
}a[100005];
bool cmp(stu x,stu y)
{
	if(x.op!=y.op)
	{
		return x.op<y.op;
	}
	return x.cha>y.cha;
}
void solve()
{
	long long n;
	cin>>n;
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
		long long mi=min(min(a[i].a,a[i].b),a[i].c);
		ans+=mi;
		a[i].a-=mi;
		a[i].b-=mi;
		a[i].c-=mi;
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
		{
			a[i].op=1;
			ans+=a[i].a;
			if(a[i].b!=0)
			{
				a[i].cha=a[i].a-a[i].b;
			}
			else
			{
				a[i].cha=a[i].a-a[i].c;
			}
		}
		if(a[i].b>a[i].a&&a[i].b>=a[i].c)
		{
			a[i].op=2;
			ans+=a[i].b;
			if(a[i].a!=0)
			{
				a[i].cha=a[i].b-a[i].a;
			}
			else
			{
				a[i].cha=a[i].b-a[i].c;
			}
		}
		if(a[i].c>a[i].a&&a[i].c>a[i].b)
		{
			a[i].op=3;
			ans+=a[i].c; 
			if(a[i].a!=0)
			{
				a[i].cha=a[i].c-a[i].a;
			}
			else
			{
				a[i].cha=a[i].c-a[i].b;
			}
		}
		//cout<<a[i].op<<" "<<a[i].cha<<endl;
	}
	sort(a+1,a+n+1,cmp);
	long long cnt1=0,cnt2=0,cnt3=0;
	for(long long i=1;i<=n;i++)
	{
		//cout<<a[i].cha<<endl;
		if(a[i].op==1)
		{
			if(cnt1==n)
			{
				ans-=a[i].cha;
			}
			else
			{
				cnt1+=2;
			}
		}
		if(a[i].op==2)
		{
			if(cnt2==n)
			{
				ans-=a[i].cha;
			}
			else
			{
				cnt2+=2;
			}
		}
		if(a[i].op==3)
		{
			if(cnt3==n)
			{
				ans-=a[i].cha;
			}
			else
			{
				cnt3+=2;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
