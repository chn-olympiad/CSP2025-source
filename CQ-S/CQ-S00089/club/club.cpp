#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define elif else if
using namespace std;
int T,n,xap[20020],ans,sum[100100],v1,v2,v3;
struct node
{
	int a[101010],b[101010],c[101010];
}x;
//struct nod
//{
//	int a,visa;
//}xa;
//bool(nod kk,nod kkk)
//{
//	return xa.a[kk]>xa.a[kkk];
//}
//struct no
//{
//	int b,visb;
//}xb;
//bool(no kk,no kkk)
//{
//	return xb.b[kk]>xb.b[kkk];
//}
void freopen_()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int xa,xb;
void init()
{
//	mamset(vis,1,sizeof(vis));
	xa=1,xb=1;
	ans=0;
	v1=0,v2=0,v3=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x.a[i] >> x.b[i] >> x.c[i];
		if(x.c[i]!=0) xb=0;
		if(x.b[i]!=0) xb=0,xa=0;
	}
}
void spa()
{
	sort(x.a+1,x.a+n+1);
	for(int i=n;i>=n/2;i--)
		ans+=x.a[i];
	cout << ans << endl;
}
//void spb()
//{
//	for(int i=1;i<=n;i++)
//	{
//		xa.visa[i]=i;
//		xa.a[i]=x.a[i];
//		xb.visb[i]=i;
//		xb.b[i]=x.b[i];
//	}
//	sort(xa+1,xa+n+1);
//	sort(xb+1,xb+n+1);
//	reverse(xa+1,xa+n+1);
//	reverse(xb+1,xb+n+1);
//	for(int i=1;i<=n/2;i++)
//	{
//		ans+=xa.a[i];
//		vis[xa.visa[i]]=0;
//	}
//	int awmax=n/2-1;
////	for(int i=1;i<=n/2;i++)
////	{
////		if(vis[xb.visb[i]]==0)
////		{
////			
////		}
////	}
//	
//}
void f(int vis)
{
	if(vis>n)
	{
		int ansx=0;
		for(int i=1;i<=n;i++)
		{
//			cout << sum[i] << " ";
			if(sum[i]==1) ansx+=x.a[i];
			if(sum[i]==2) ansx+=x.b[i];
			if(sum[i]==3) ansx+=x.c[i];
		}
//		cout << endl;
		ans=max(ans,ansx);
		return;
	}
	if(v1<n/2)
	{
		v1++;
		sum[vis]=1;
		f(vis+1);
		v1--;
	}
	if(v2<n/2)
	{
		v2++;
		sum[vis]=2;
		f(vis+1);
		v2--;
	}
	if(v3<n/2)
	{
		v3++;
		sum[vis]=3;
		f(vis+1);
		v3--;
	}
	
}
void baoli()
{
	f(1);
	cout << ans << endl;
}
void solve()
{
	init();
	if(xa) spa();
//	elif(xb) spb();
	else baoli();
}
signed main()
{
	freopen_();
	cin >> T;
	while(T--)
		solve();
	return 0;
}
/*
1
4
3 0 0
10 0 0
1 0 0
7 0 0

1
4
3 6 0
10 20 0
1 7 0
7 2 0

10 7

1 4
1 2 3
1 2 3
1 2 3
1 2 3

*/

