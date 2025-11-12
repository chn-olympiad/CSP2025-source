#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010

/*同一时刻，至多有一个部门人数超过n/2。
若有部门人数超过n/2，令该部门某人去往其他部门，不可能造成
某一部门人数超过n/2。
则先让所有人贪心地去最满意的部门，然后如果有部门人数超标，
依次弹出直到剩下n/2个人，让这些人去自己第二满意的部门。*/

int T,n,ans,cnt[4];
struct node{
	int v,id;
}a[N][4];
priority_queue<int> q[4];

bool cmp(node x,node y){
	return x.v>y.v;
}

void Clear(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			a[i][j].v=a[i][j].id=0;
		}
	}cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=3;i++){
		while(!q[i].empty()) q[i].pop();
	}ans=0;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n; int lim=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].v;
				a[i][j].id=j;
			}sort(a[i]+1,a[i]+4,cmp);
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][1].v;
			q[a[i][1].id].push(a[i][2].v-a[i][1].v);
			cnt[a[i][1].id]++;
		}
		if(cnt[1]>lim){
			while(cnt[1]>lim){
				ans+=q[1].top(); q[1].pop(); cnt[1]--;
			}
		}else if(cnt[2]>lim){
			while(cnt[2]>lim){
				ans+=q[2].top(); q[2].pop(); cnt[2]--;
			}
		}else if(cnt[3]>lim){
			while(cnt[3]>lim){
				ans+=q[3].top(); q[3].pop(); cnt[3]--;
			}
		}cout<<ans<<"\n"; Clear(); continue;
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
