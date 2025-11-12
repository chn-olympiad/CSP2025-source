#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxn2=210;
long long ans=0,t,n,cnt[10],dp[210][210][210];
bool vis[maxn];
struct node
{
	int a,b,c,mx1,mx2,mx3,mx;
}k[maxn];
void check(int i)
{
	if(k[i].a>=k[i].b && k[i].a>=k[i].c){
		k[i].mx1=1;
		k[i].mx=k[i].a;
		if(k[i].b>=k[i].c){
			k[i].mx2=2;
			k[i].mx3=3;
		}
		else{
			k[i].mx2=3;
			k[i].mx3=2;	
		}
	}
	else 
	{
		if(k[i].b>=k[i].c && k[i].b>=k[i].a){
		k[i].mx1=2;
		k[i].mx=k[i].b;
		if(k[i].a>=k[i].c){
			k[i].mx2=1;
			k[i].mx3=3;
		}
		else{
			k[i].mx2=3;
			k[i].mx3=1;	
		}
	}
	else
	{
		if(k[i].c>=k[i].b && k[i].c>=k[i].a){
			k[i].mx1=3;
			k[i].mx=k[i].c;
			if(k[i].b>=k[i].a){
				k[i].mx2=2;
				k[i].mx3=1;
			}
			else{
				k[i].mx2=1;
				k[i].mx3=2;	
				}
			}	
		}
	}	
}
bool cmp(node a,node b)
{
	return a.mx>b.mx;
}
int change(int i,int p)
{
	if(p==1) return k[i].a;
	if(p==2) return k[i].b;
	if(p==3) return k[i].c;
	return 0;
}
void solve()
{
	sort(k+1,k+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(cnt[k[i].mx1] < (n/2) && (!vis[i]))
		{
		ans+=k[i].mx;
		vis[i]=true;
		cnt[k[i].mx1]++;	
		}
		k[i].mx=change(i,k[i].mx2);
	}
	sort(k+1,k+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(cnt[k[i].mx2] < (n/2) && (!vis[i]))
		{
		ans+=k[i].mx;
		vis[i]=true;
		cnt[k[i].mx2]++;	
		}
		k[i].mx=change(i,k[i].mx3);
	}
	sort(k+1,k+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(cnt[k[i].mx3] < (n/2) && (!vis[i]))
		{
		vis[i]=true;
		ans+=k[i].mx;
		cnt[k[i].mx3]++;	
		}
	}
	cout<<ans<<endl;
}
void init()
{
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
			check(i);	
		}	
		solve();
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	init();
	return 0;
 } 
 /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
