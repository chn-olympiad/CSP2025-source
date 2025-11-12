#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int N = 1e5+3;
int n,t,cnt[3];
long long res;
struct node{
	int val,frn,id;
	bool operator< (const node &u) const{
		return u.val<val;
	}
};
priority_queue<node> q[3];
struct node2{
	int val,id,frn;
	bool operator< (const node2 &u) const{
		return u.val>val;
	}
};
priority_queue<node2> h;
struct node3{
	int val,frn;
}a[N][3];
inline bool cmp(node3 x,node3 y){
	return x.val>y.val;
}
void clear(){
	res=0;
	while(h.size()) h.pop();
	for(int i=0;i<3;++i) while(q[i].size()) q[i].pop();
	for(int i=0;i<3;++i) cnt[i]=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		clear();
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>a[i][j].val;
				a[i][j].frn=j;
			}
			stable_sort(a[i],a[i]+3,cmp);
			h.push({a[i][0].val,i,a[i][0].frn});
		}
		while(h.size()){
			auto t=h.top();
			h.pop();
			if(cnt[t.frn]<n/2){
				++cnt[t.frn];
				q[t.frn].push({a[t.id][0].val-a[t.id][1].val,a[t.id][1].frn,t.id});
				res+=a[t.id][0].val;
			}else{
				auto k=q[t.frn].top();
				if(k.val<a[t.id][0].val-a[t.id][1].val){  //损失没有那么大
					q[t.frn].pop();
					q[t.frn].push({a[t.id][0].val-a[t.id][1].val,a[t.id][1].frn,t.id});
					q[a[k.id][1].frn].push({a[k.id][1].val-a[k.id][2].val,a[k.id][2].frn,k.id});
					++cnt[a[k.id][1].frn];
					res+=t.val;
					res-=a[k.id][0].val;
					res+=a[k.id][1].val;
				}else{
					q[a[t.id][1].frn].push({a[t.id][1].val-a[t.id][2].val,a[t.id][2].frn,t.id});
					++cnt[a[t.id][1].frn];
					res+=a[t.id][1].val;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1

*/