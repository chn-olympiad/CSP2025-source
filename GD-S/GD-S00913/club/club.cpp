#include<bits/stdc++.h>
using namespace std;
int t,n,tmp[100001];
struct p
{
	int a[4];
	bool f;
}c[100001];
int pw(int a,int b,int c,int x)
{
	if (x==1)
	{
		return min(a,min(b,c));
	}
	if (x==3)
	{
		return max(a,max(b,c));
	}
	return a+b+c-min(a,min(b,c))-max(a,max(b,c));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int cnt1=0,cnt2=0,cnt3=0,sum=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			int now;
			cin>>c[i].a[1]>>c[i].a[2]>>c[i].a[3];
			now=max(c[i].a[1],max(c[i].a[2],c[i].a[3]));
			if (c[i].a[1]==now) cnt1++;
			if (c[i].a[2]==now) cnt2++;
			if (c[i].a[3]==now) cnt3++;
			sum+=now;
		}
		if (cnt1>n/2)
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				int now;
				now=max(c[i].a[1],max(c[i].a[2],c[i].a[3]));
				if (c[i].a[1]==now) 
				{
					cnt++;
					tmp[cnt]=now-pw(c[i].a[1],c[i].a[2],c[i].a[3],2);
				}
			}
			sort(tmp+1,tmp+1+cnt);
			int i=1;
			while(cnt1>n/2)
			{
				sum-=tmp[i++];
				
				cnt1--;
			}
		}
		else if (cnt2>n/2)
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				int now;
				now=max(c[i].a[1],max(c[i].a[2],c[i].a[3]));
				if (c[i].a[2]==now) 
				{
					cnt++;
					tmp[cnt]=now-pw(c[i].a[1],c[i].a[2],c[i].a[3],2);
				}
			}
			sort(tmp+1,tmp+1+cnt);
			int i=1;
			while(cnt2>n/2)
			{
				sum-=tmp[i++];
				cnt2--;
			}
		}
		else if (cnt3>n/2)
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				int now;
				now=max(c[i].a[1],max(c[i].a[2],c[i].a[3]));
				if (c[i].a[3]==now) 
				{
					cnt++;
					tmp[cnt]=now-pw(c[i].a[1],c[i].a[2],c[i].a[3],2);
				}
			}
			sort(tmp+1,tmp+1+cnt);
			int i=1;
			while(cnt3>n/2)
			{
				sum-=tmp[i++];
				cnt3--;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
//*** have no egg
