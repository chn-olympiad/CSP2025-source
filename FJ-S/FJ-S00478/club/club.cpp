#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10; 
typedef long long ll; 

//vector<vector<ll>> m;
ll dp[N][5][N]; 
struct Node
{
	ll x,A,B,C; 
 } ;
ll max3(ll a,ll b,ll c)
{
	return max(max(a,b),c );
 } 
Node m[N],a[N],b[N],c[N];
bool cmp1(Node a,Node b)
{
	return a.A>b.A; 
 } 
bool cmp2(Node a,Node b)
{
	return a.B>b.B; 
 } 
bool cmp3(Node a,Node b)
{
	return a.C>b.C; 
 } 
bool cmp(Node a,Node b)
{
	return a.x>b.x; 
 } 
int  main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	
	//FREOPEN( "XXX.IN(OUT)" , "R(W)" , STD IN(OUT) ) ; 
	int t,n;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		//memset(w,0,sizeof(w)); 
		cin>>n;
		ll w1=0,w2=0,w3=0; 
		for(int i=1;i<=n;i++) 
			cin>>m[i].A>>m[i].B>>m[i].C;//value 
		sort(m+1,m+n+1,cmp1);
		for(int i=1;i<=n/2;i++)
		{
			a[i]=m[i]; 
		 } 
		sort(m+1,m+n+1,cmp2);
		for(int i=1;i<=n/2;i++)
		{
			b[i]=m[i]; 
		 }
		sort(m+1,m+n+1,cmp3); 
		for(int i=1;i<=n/2;i++)
		{
			c[i]=m[i]; 
		 }
		//检查重复
		//sort(m+1,m+n+1,cmp); 
		for(int i=1;i<=n/2;i++)
		{
			if(a[i].x==b[i].x)
			{
				if(a[i].A<b[i].B) 
				{
					m[i].A=0; 
					sort(m+1,m+n+1,cmp1);
					a[i]=m[i]; 
				}
				else if(a[i].A>b[i].B) 
				{
					m[i].B=0; 
					sort(m+1,m+n+1,cmp2);
					b[i]=m[i]; 
				} 
			 } 
		 } 
		for(int i=1;i<=n/2;i++)
		{
			if(c[i].x==b[i].x)
			{
				if(c[i].C<b[i].B) 
				{
					m[i].C=0; 
					sort(m+1,m+n+1,cmp3);
					c[i]=m[i]; 
				}
				else if(c[i].C>b[i].B) 
				{
					m[i].B=0; 
					sort(m+1,m+n+1,cmp2);
					b[i]=m[i]; 
				} 
			 } 
		 } 
		for(int i=1;i<=n/2;i++)
		{
			if(a[i].x==c[i].x)
			{
				if(a[i].A<c[i].C) 
				{
					m[i].A=0; 
					sort(m+1,m+n+1,cmp1);
					a[i]=m[i]; 
				}
				else if(a[i].A>c[i].C) 
				{
					m[i].C=0; 
					sort(m+1,m+n+1,cmp3);
					c[i]=m[i]; 
				} 
			 } 
		 } 
		for(int i=1;i<=n/2;i++)
		{
			if(a[i].x==b[i].x)
			{
				if(a[i].A<b[i].B) 
				{
					m[i].A=0; 
					sort(m+1,m+n+1,cmp1);
					a[i]=m[i]; 
				}
				else if(a[i].A>b[i].B) 
				{
					m[i].B=0; 
					sort(m+1,m+n+1,cmp2);
					b[i]=m[i]; 
				} 
			 } 
		 }  
		//求和
		ll ans=0; 
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].A+b[i].B+c[i].C; 
		 } 
		 cout<<ans<<endl ;  
	}
	
	return 0;
}
