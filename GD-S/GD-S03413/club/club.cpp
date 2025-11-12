#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=3e5+5;
int T,n,ids[MAXN],ans;
int num[5],sum,mid_max[MAXN];
bool vis[MAXN];
struct out{ 
	int k,id;
} a[5];
int cmp2(out x,out y) 
{ 
	return x.k<y.k;
} 
priority_queue<int> q[5];
struct people{ 
	int k,pos,id;
} p[MAXN];
int cmp(people x,people y) 
{ 
	return x.k>y.k;
} 
int main() 
{ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) 
	{ 
		cin>>n;
		for(int i=1;i<=n;++i) 
		{ 
			for(int j=1;j<=3;++j) 
			{ 
				cin>>a[j].k;
				a[j].id=j;
				p[++ans].k=a[j].k;
				p[ans].pos=i;
				p[ans].id=j;
			} 
			sort(a+1,a+4,cmp2);
			mid_max[i]=a[2].k;
			ids[i]=a[2].id;
		} 
		sort(p+1,p+1+ans,cmp);
		for(int i=1;i<=ans;++i) 
		{ 
			if(vis[p[i].pos]) continue;
			if(num[p[i].id]<n/2) 
			{ 
				++num[p[i].id];
				sum+=p[i].k;
				q[p[i].id].push(mid_max[p[i].pos]-p[i].k);
			} 
			else
			{ 
				if(!q[p[i].id].empty()) 
				{ 
					if(mid_max[p[i].pos]-p[i].k>=q[p[i].id].top()) continue;
					sum+=q[p[i].id].top()+p[i].k;
					q[p[i].id].pop();
					q[p[i].id].push(mid_max[p[i].pos]-p[i].k);
				} 
			} 
			vis[p[i].pos]=true;
		} 
		cout<<sum<<"\n";
		memset(num,0,sizeof num);
		memset(vis,false,sizeof vis);
		sum=ans=0;
		for(int i=1;i<=3;++i) 
			while(!q[i].empty()) q[i].pop();
	} 

	return 0;
} 
