#include<bits/stdc++.h>
using namespace std;
struct pp{
	int c1,c2,f1,f2,f3,id;
	int like[3];
}a[100005];
int n,n2;
bool cmp(pp s,pp b)
{
	if(s.c1!=b.c1)return s.c1>b.c1;
	if(s.c2!=b.c2)return s.c2>b.c2;
	if(s.like[s.f1]!=b.like[b.f1])return s.like[s.f1]>b.like[b.f1];
	if(s.like[s.f2]!=b.like[b.f2])return s.like[s.f2]>b.like[b.f2];
	return s.like[s.f3]>b.like[b.f3];
}
int f()
{
	int ans=0;
	int xuan[3]={0};
	for(int i=0;i<n;i++)
	{
		if(xuan[a[i].f1]<n2)
		{
			xuan[a[i].f1]++;
			ans+=a[i].like[a[i].f1];
//			cout<<a[i].id<<" + "<<a[i].f1;
		}
		else if(xuan[a[i].f2]<n2)
		{
			xuan[a[i].f2]++;
			ans+=a[i].like[a[i].f2];
//			cout<<a[i].id<<" + "<<a[i].f2;
		}
		else
		{
			xuan[a[i].f3]++;
			ans+=a[i].like[a[i].f3];
///			cout<<a[i].id<<" + "<<a[i].f3;
		}
//		cout<<"\n";
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		a[i].id=i;
		cin>>a[i].like[0]>>a[i].like[1]>>a[i].like[2];
		if(a[i].like[0]>=a[i].like[1]&&a[i].like[0]>=a[i].like[2])
		{
			a[i].f1=0;
			if(a[i].like[1]>=a[i].like[2])
			{
				a[i].f2=1;
				a[i].f3=2;
				a[i].c1=a[i].like[0]-a[i].like[1];
				a[i].c2=a[i].like[1]-a[i].like[2];
			}
			else 
			{
				a[i].f2=2;
				a[i].f3=1;
				a[i].c1=a[i].like[0]-a[i].like[2];
				a[i].c2=a[i].like[2]-a[i].like[1];
			}
		}
		else if(a[i].like[1]>=a[i].like[2])
		{
			a[i].f1=1;
			if(a[i].like[0]>=a[i].like[2])
			{
				a[i].f2=0;
				a[i].f3=2;
				a[i].c1=a[i].like[1]-a[i].like[0];
				a[i].c2=a[i].like[0]-a[i].like[2];
			}
			else 
			{
				a[i].f2=2;
				a[i].f3=0;
				a[i].c1=a[i].like[1]-a[i].like[2];
				a[i].c2=a[i].like[2]-a[i].like[0];
			}
		}
		else
		{
			a[i].f1=2;
			if(a[i].like[0]>=a[i].like[1])
			{
				a[i].f2=0;
				a[i].f3=1;
				a[i].c1=a[i].like[2]-a[i].like[0];
				a[i].c2=a[i].like[0]-a[i].like[1];
			}
			else 
			{
				a[i].f2=1;
				a[i].f3=0;
				a[i].c1=a[i].like[2]-a[i].like[1];
				a[i].c2=a[i].like[1]-a[i].like[0];
			}
		}
	}
	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i].id<<" "<<a[i].f1<<" "<<a[i].f2<<" "<<a[i].f3<<" "<<a[i].c1<<" "<<a[i].c2<<"\n";
//	}
	n2=n/2;
	cout<<f()<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

