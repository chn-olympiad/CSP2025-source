#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100001][4],m[100001];
struct node
{
	ll id,val;
}b[100001];
inline ll read()
{
	ll s=0,f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(f=='-');
	for(;isdigit(ch);ch=getchar()) s=(s<<3)+(s<<1)+(ch^48);
	return f?-s:s;
}
inline void sw(ll &x,ll &y)
{
	ll t=x;
	x=y;
	y=t;
}
inline bool cmp(node x,node y)
{
	return x.val<y.val;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		ll s1=0,s2=0,s3=0;
		n=read();
		for(ll i=1;i<=n;i++)
		{
			b[i].id=i;
			for(ll j=1;j<=3;j++) a[i][j]=read();
			m[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			if(m[i]==a[i][1]) s1++;
			else if(m[i]==a[i][2]) s2++;
			else s3++;
		}
		if(s1<=n/2 && s2<=n/2 && s3<=n/2)
		{
			ll sum=0;
			for(ll i=1;i<=n;i++) sum+=m[i];
			cout<<sum<<"\n";
			continue;
		}
		if(s2>n/2)
		{
			for(ll i=1;i<=n;i++) sw(a[i][1],a[i][2]);
			sw(s1,s2);
		}
		else if(s3>n/2)
		{
			for(ll i=1;i<=n;i++) sw(a[i][1],a[i][3]);
			sw(s1,s3);
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++) if(m[i]==a[i][1]) b[++cnt].val=m[i]-max(a[i][2],a[i][3]);
		sort(b+1,b+s1+1,cmp);
		for(ll i=1;i<=s1-n/2;i++)
		{
			m[b[i].id]-=b[i].val;
		}
		ll sum=0;
		for(ll i=1;i<=n;i++) sum+=m[i];
		cout<<sum<<"\n";
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

*/
