#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,id;
	bool operator <(node o)const{
		return x>o.x;
	}
}a[100010][5];

int b[100010],n,k,lst;
long long ans;
priority_queue<node> q[4];

void clear(){
	priority_queue<node> q1[4];
	swap(q[1],q1[1]),swap(q[2],q1[2]),swap(q[3],q1[3]);
	ans=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		clear();
		cin>>n;
		k=n/2;
		for(int i = 1;i <= n;i++){
			cin>>a[i][1].x>>a[i][2].x>>a[i][3].x;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4);
			b[i]=1;
		}
		for(int i = 1;i <= n;i++){
			q[a[i][1].id].push({a[i][1].x-a[i][2].x,i});
			ans+=a[i][1].x;
			lst=a[i][1].id;
			while(q[lst].size()>k){
				auto ed=q[lst].top();
				q[lst].pop();
				int u=ed.id;
				ans-=a[u][b[u]].x;
				b[u]++;
				ans+=a[u][b[u]].x;
				q[a[u][b[u]].id].push({a[u][b[u]].x-a[u][b[u]+1].x,u});
				lst=a[u][b[u]].id;
			}
		}cout<<ans<<'\n';
	}
	return 0;
}
