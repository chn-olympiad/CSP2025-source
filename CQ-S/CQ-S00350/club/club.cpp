#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;
int t,n,ans;
int cnt[4];
struct node{
	int id,val;
	bool operator <(const node &x) const{
		return val==x.val?id<x.id:val>x.val;
	}
}a[maxn][4];
priority_queue<int,vector<int>,greater<int> > q[4];

inline void init(){
	ans=0;
	for(int i=1;i<=3;i++){
		cnt[i]=0;
		while(!q[i].empty()) q[i].pop();
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n),init(); 
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1].val,&a[i][2].val,&a[i][3].val);
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4);
		}
		for(int i=1;i<=n;i++){
			cnt[a[i][1].id]++;
			ans+=a[i][1].val;
			q[a[i][1].id].push(a[i][1].val-a[i][2].val);
		}
		for(int i=1;i<=3;i++){
			while(cnt[i]>n/2){
				ans-=q[i].top();
				q[i].pop();
				cnt[i]--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
