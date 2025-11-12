#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
int t,n,cnt[10];
struct node{
	int v,t;
}a[maxn][10];
bool cmp(node x,node y){
	return x.v>y.v;
}
struct point{
	int id,fi,v;
	bool operator<(const point x)const{
		return a[id][fi].v-a[id][fi+1].v>x.v-a[x.id][x.fi+1].v;
	}
};
priority_queue<point>q[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		for(int i=1;i<=3;i++){
			while(!q[i].empty())q[i].pop();
		}
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
			a[i][1].t=1;a[i][2].t=2;a[i][3].t=3;
			sort(a[i]+1,a[i]+4,cmp);
			ans+=a[i][1].v;
			cnt[a[i][1].t]++;
			q[a[i][1].t].push(point{i,1,a[i][1].v});
		}
		while(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2){
			for(int i=1;i<=3;i++){
				if(cnt[i]<=n/2)continue;
				while(cnt[i]>n/2){
					while(q[i].top().fi==3)q[i].pop();
					point x=q[i].top();q[i].pop();
					ans+=a[x.id][x.fi+1].v-x.v;
					if(x.fi==1){
						q[a[x.id][2].t].push(point{x.id,2,a[x.id][2].v});
					}
					cnt[i]--;cnt[a[x.id][x.fi+1].t]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
