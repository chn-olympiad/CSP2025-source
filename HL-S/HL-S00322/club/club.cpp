#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
struct A
{
	int a1,a2,a3,id;
}a[100005],w1,w2;
bool cmp1(A a,A b)
{
	if(a.id==b.id)
	{
		if(a.id==1) return a.a1>b.a1;
		else return a.a2>b.a2;
	}
	else return a.id<b.id;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		ans=0;
		cin >>n;
		if(n==2)
		{
			cin >>w1.a1>>w1.a2>>w1.a3>>w2.a1>>w2.a2>>w2.a3;
			if(w1.a1>=w1.a2&&w1.a1>=w1.a3) w1.id=1;
			else if(w1.a2>=w1.a1&&w1.a2>=w1.a3) w1.id=2;
			else if(w1.a3>=w1.a1&&w1.a3>=w1.a2) w1.id=3;
			
			if(w2.a1>=w2.a2&&w2.a1>=w2.a3) w2.id=1;
			else if(w2.a2>=w2.a1&&w2.a2>=w2.a3) w2.id=2;
			else if(w2.a3>=w2.a1&&w2.a3>=w2.a2) w2.id=3;
			
			if(w1.id!=w2.id)
			{
				if(w1.id==1) ans+=w1.a1;
				else if(w1.id==2) ans+=w1.a2;
				else if(w1.id==3) ans+=w1.a3;
				
				if(w2.id==1) ans+=w2.a1;
				else if(w2.id==2) ans+=w2.a2;
				else if(w2.id==3) ans+=w2.a3;
			}
			else
			{
				if(w1.id==1)
				{
					if(w1.a1==w2.a1)
					{
						ans+=w1.a1;
						ans+=max(max(w1.a2,w1.a3),max(w2.a2,w2.a3));
					}
					else if(w1.a1>w2.a1)
					{
						ans+=w1.a1;
						ans+=max(w2.a2,w2.a3);
					}
					else if(w1.a1<w2.a1)
					{
						ans+=w2.a1;
						ans+=max(w1.a2,w1.a3);
					}
				}
				else if(w1.id==2)
				{
					if(w1.a2==w2.a2)
					{
						ans+=w1.a2;
						ans+=max(max(w1.a1,w1.a3),max(w2.a1,w2.a3));
					}
					else if(w1.a2>w2.a2)
					{
						ans+=w1.a2;
						ans+=max(w2.a1,w2.a3);
					}
					else if(w1.a2<w2.a2)
					{
						ans+=w2.a2;
						ans+=max(w1.a1,w1.a3);
					}
				}
				else if(w1.id==3)
				{
					if(w1.a3==w2.a3)
					{
						ans+=w1.a3;
						ans+=max(max(w1.a1,w1.a2),max(w2.a1,w2.a2));
					}
					else if(w1.a3>w2.a3)
					{
						ans+=w1.a3;
						ans+=max(w2.a1,w2.a2);
					}
					else if(w1.a3<w2.a3)
					{
						ans+=w2.a3;
						ans+=max(w1.a1,w1.a2);
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin >>a[i].a1>>a[i].a2>>a[i].a3;
				if(a[i].a1>=a[i].a2)a[i].id=1;
				else a[i].id=2;
			}
			sort(a+1,a+n+1,cmp1);
			bool flag=false;
			int w;
			for(int i=1;i<=n/2;i++)
			{
				if(a[i].id!=1)
				{
					w=i;
					flag=true;
					break;
				}
				ans+=a[i].a1;
			}
			if(flag)
			{
				for(int i=w;i<=w+n/2-1;i++)
				{
					ans+=a[i].a2;
				}
				for(int i=w+n/2;i<=n;i++)
				{
					ans+=a[i].a1;
				}
			}
			else
			{
				for(int i=n/2+1;i<=n;i++)
				{
					ans+=a[i].a2;
				}
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
