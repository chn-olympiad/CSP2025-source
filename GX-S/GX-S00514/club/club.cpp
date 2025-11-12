#include<bits/stdc++.h>
using namespace std;
struct sss
{
	int a,b,c,d;
}q[100008];
bool cmp(sss e,sss f)
{
	return e.d>f.d;
}
int t,n,m,xxx=0,yyy=0,zzz=0;
long long ans,sum[1145],oo,ooo;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		xxx=0,yyy=0,zzz=0,oo=0,ooo=0;
		cin>>n;
		m=n/2;
		for(int j=0;j<n;j++)
		{
			cin>>q[j].a>>q[j].b>>q[j].c;
			if(q[j].c==0&&q[j].b==0) oo++;
			else if(q[j].c==0&&q[j].b!=0) ooo++;
			int num=max(q[j].a,q[j].b);
			q[j].d=max(num,q[j].c);
		}
		sort(q,q+n,cmp);
		if(oo==n)
		{
			for(int j=0;j<m;j++)
			{
				ans=ans+q[j].d;
			}
			sum[i]=ans;
			ans=0;
			continue;
		}
		for(int j=0;j<n;j++)
		{
			if(q[j].a>q[j].b&&q[j].a>q[j].c) xxx=xxx+1;
			if(q[j].b>q[j].c&&q[j].b>q[j].a) yyy=yyy+1;
			if(q[j].c>q[j].b&&q[j].c>q[j].a) zzz=zzz+1;
			if(xxx>m) ans=ans+max(q[j].b,q[j].c);
			else if(yyy>m) ans=ans+max(q[j].a,q[j].c);
			else if(zzz>m) ans=ans+max(q[j].a,q[j].b);
			else ans=ans+q[j].d;
		}
		sum[i]=ans;
		ans=0;
	}
	for(int i=0;i<t;i++) cout<<sum[i]<<endl;
	return  0;
}
