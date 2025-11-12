#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long t,n,maxn,cnt,n1,n2,n3;
struct node
{
	long long a1;
	long long a2;
	long long a3;
}a[100005];
bool cmp1(node a,node b)
{
	return a.a1>b.a1;
}
bool cmp2(node a,node b)
{
	return a.a2>b.a2;
}
bool cmp3(node a,node b)
{
	return a.a3>b.a3;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		cnt=0;
		n1=0;
		n2=0;
		n3=0;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(maxn==a[i].a1)
				n1++;
			else if(maxn==a[i].a2)
				n2++;
			else if(maxn==a[i].a3)
				n3++;
			cnt+=maxn;
			a[i].a1-=maxn;
			a[i].a2-=maxn;
			a[i].a3-=maxn;
		}
		while(n1>n/2)
		{
			for(int i = 1;i<=n;i++)
			{
				if((a[i].a2==0||a[i].a3==0)&&a[i].a1!=0)
				{
					a[i].a2=-1e8;
					a[i].a3=-1e8;
				}
			}
			sort(a+1,a+n+1,cmp2);
			maxn=a[1].a2;
			sort(a+1,a+n+1,cmp3);
			if(maxn>a[1].a3)
			{
				sort(a+1,a+n+1,cmp2);
				cnt+=a[1].a2;
				a[1].a2=-1e8;
				a[1].a3=-1e8;
			}
			else
			{
				cnt+=a[1].a3;
				a[1].a3=-1e8;
				a[1].a2=-1e8;
			}
			n1--;
		}
		while(n2>n/2)
		{
			for(int i = 1;i<=n;i++)
			{
				if((a[i].a1==0||a[i].a3==0)&&a[i].a2!=0)
				{
					a[i].a1=-1e8;
					a[i].a3=-1e8;
				}
			}
			sort(a+1,a+n+1,cmp1);
			maxn=a[1].a1;
			sort(a+1,a+n+1,cmp3);
			if(maxn>a[1].a3)
			{
				sort(a+1,a+n+1,cmp1);
				cnt+=a[1].a1;
				a[1].a1=-1e8;
				a[1].a3=-1e8;
			}
			else
			{
				cnt+=a[1].a3;
				a[1].a3=-1e8;
				a[1].a1=-1e8;
			}
			n2--;
		}
		while(n3>n/2)
		{
			for(int i = 1;i<=n;i++)
			{
				if((a[i].a1==0||a[i].a2==0)&&a[i].a3!=0)
				{
					a[i].a1=-1e8;
					a[i].a2=-1e8;
				}
			}
			sort(a+1,a+n+1,cmp1);
			maxn=a[1].a1;
			sort(a+1,a+n+1,cmp2);
			if(maxn>a[1].a2)
			{
				sort(a+1,a+n+1,cmp1);
				cnt+=a[1].a1;
				a[1].a1=-1e8;
				a[1].a2=-1e8;
			}
			else
			{
				cnt+=a[1].a2;
				a[1].a2=-1e8;
				a[1].a1=-1e8;
			}
			n3--;
		}
		cout << cnt << endl;
	}
	return 0;
}
