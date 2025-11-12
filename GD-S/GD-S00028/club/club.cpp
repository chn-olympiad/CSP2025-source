#include<bits/stdc++.h>
using namespace std;
#define lnt long long
const int N=1e5+5;
int t,n,ct[5];
struct node
{
	int x,y,z,m,id;
}a[N];
bool cmp(node x,node y)
{
	return x.m>y.m;
}
void turn()
{
	for(int i=1; i<=n; i++)
	{
		a[i].m=0;
		if(a[i].x>a[i].m)a[i].m=a[i].x,a[i].id=1;
		if(a[i].y>a[i].m)a[i].m=a[i].y,a[i].id=2;
		if(a[i].z>a[i].m)a[i].m=a[i].z,a[i].id=3;
	}
}
bool f[5];
signed main(){
	//feropen()
	//哈哈，中计了吧 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		lnt ans=0,cts=0;
		memset(f,1,sizeof f);
		memset(ct,0,sizeof ct);
		for(int i=1; i<=n; i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		while(cts<n)
		{
			bool fl=0;
			turn();
			sort(a+1,a+1+n,cmp);
			for(int i=1; i<=n; i++)
			{
				if(fl)
				{
					if(!f[a[i].id])a[i].x=a[i].y=a[i].z=0;
				}
				else if(f[a[i].id])
				{
					ans+=a[i].m,ct[a[i].id]++,cts++;
					a[i].x=a[i].y=a[i].z=0;
					if(ct[a[i].id]==n/2)f[a[i].id]=0,fl=1;
				}
				
			}
			if(!fl)break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//luogu uid 642434 快关注我 
