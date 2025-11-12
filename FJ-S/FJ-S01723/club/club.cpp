#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][6];
int d[6];
struct e
{
	int k,s; 
}h[N][5];
priority_queue<pair<int,int> > q[3];
long long ans;
inline void f(e ax,e by)
{
	if(h[ax.k][2].s>h[by.k][2].s){
		q[ax.k].push(make_pair(ax.s,ax.k));
		q[h[by.k][2].k].push(make_pair(h[by.k][2].s,h[by.k][2].k));
		d[h[by.k][2].k]++;
		ans-=(h[by.k][2].s-by.s);
	}
	else if(h[ax.k][2].s<h[by.k][2].s){
		q[by.k].push(make_pair(by.s,by.k));
		q[h[ax.k][2].k].push(make_pair(h[ax.k][2].s,h[ax.k][2].k));
		d[h[ax.k][2].k]++;
		ans-=(h[ax.k][2].s-ax.s);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		while(q[1].size())q[1].pop();
		while(q[2].size())q[2].pop();
		while(q[3].size())q[3].pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][4]=a[i][1]+a[i][2]+a[i][3];
			h[i][1].s=a[i][4]-a[i][1];h[i][1].k=1;
			h[i][2].s=a[i][4]-a[i][2];h[i][2].k=2;
			h[i][3].s=a[i][4]-a[i][3];h[i][3].k=3;
			if(h[i][2].s>h[i][3].s){
				swap(h[i][2],h[i][3]);
			}
			if(h[i][1].s>h[i][2].s){
				swap(h[i][1],h[i][2]);
			}
			if(h[i][2].s>h[i][3].s){
				swap(h[i][2],h[i][3]);
			}
			ans+=a[i][4];
		}
		for(int i=1;i<=n;i++){
			int hs=h[i][1].s,kkl=h[i][1].k;
			if(d[kkl]==n/2){
				int xl=q[kkl].top().first,y=q[kkl].top().second;
				q[kkl].pop();
				int xsl=q[kkl].top().first,ys=q[kkl].top().second;
				q[kkl].pop();
				e x={xl,y};
				e xs={xsl,ys};
				if(min(x.s,min(xs.s,h[i][1].s))==h[i][1].s){
					f(x,xs);
					q[kkl].push(make_pair(h[i][1].s,h[i][1].k));
				}
				else if(x.s>h[i][1].s){
					f(x,h[i][1]);
					q[kkl].push(make_pair(xs.s,xs.k));
				}
				else{
					f(xs,h[i][1]);
					q[kkl].push(make_pair(x.s,x.k));
				}
			}
			else{
				q[kkl].push(make_pair(h[i][1].s,h[i][1].k));
				ans-=h[i][1].s;
				d[kkl]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
