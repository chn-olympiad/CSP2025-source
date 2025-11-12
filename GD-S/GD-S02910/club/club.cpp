#include <bits/stdc++.h>
#define ll long long
#define fre(c) 
using namespace std;
ll n,m,a,b,c,t[300005],k[4];
struct node
{
	ll num,id,h;
}e[300005];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
int main() {
	freopen("club5.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--) 
	{
		cin>>m;
		memset(k,0,sizeof(k));
		memset(t,0,sizeof(t));
		ll tot=0;
		for(ll i=1;i<=m;i++)
		{
			cin>>a;
			e[++tot]={a,i,1};
			cin>>b;
			e[++tot]={b,i,2};
			cin>>c;
			e[++tot]={c,i,3};
		}
		ll mx=m/2,ans=0;
		sort(e+1,e+tot+1,cmp);
//		for(ll i=1;i<=tot;i++)
//		{
//			cout<<e[i].num<<" ";
//		}
		for(ll i=1;i<=tot;i++) 
		{
			if(t[e[i].id]==0&&k[e[i].h]+1<=mx) 
			{
				ans+=e[i].num;
				t[e[i].id]=1;
				k[e[i].h]++;
			}
		}
		cout<<ans<<endl;
	}
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
