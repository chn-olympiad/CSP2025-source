#include<bits/stdc++.h>
using namespace std;
template<typename type>
inline void read(type &x){
	x=0;bool flag(0);char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}
#define ll long long
const int N=1e4+100;
int n,m,k,a[11];
ll f[11][10001];
ll ans;
bool used[N],use[11]; 
struct node{
	int to;
	ll w;
	operator < (const node &x) const {
		return w>x.w;
	}
};
vector<node> e[N];
priority_queue<node> pq;
void find(int id){
	used[id]=1;
//	cout<<"id="<<id<<endl;
	for(int i=0;i<e[id].size();i++){
//		cout<<id<<" "<<e[id][i].to<<" "<<used[e[id][i].to]<<endl;
		if(used[e[id][i].to]) continue;
		pq.push(e[id][i]);
	}
	node to;
	do{
		to=pq.top();
		pq.pop();
//		cout<<"to="<<to.to<<" w="<<to.w<<endl;
	}while(!pq.empty()&&used[to.to]==1);
	if(used[to.to]) return;
	ll mn,sum;
	int point=0;
	mn=to.w;
	for(int i=1;i<=k;i++){
		sum=f[i][id]+f[i][to.to]+(use[i]?0:a[i]);
		if(to.w>=sum){
			mn=min(sum,mn);
			if(mn==sum) point=i;
		}
	}
//	if(mn!=to.w||point!=0) cout<<"mn="<<mn<<" point="<<point<<endl;
	if(point!=0){
		for(int i=1;i<=n;i++) pq.push({i,f[point][i]});
	} 
	ans+=mn;
	use[point]=1;
	find(to.to);
	return;
}
void findd(int id){
	used[id]=1;
//	cout<<"id="<<id<<endl;
	for(int i=0;i<e[id].size();i++){
//		cout<<id<<" "<<e[id][i].to<<" "<<used[e[id][i].to]<<endl;
		if(used[e[id][i].to]) continue;
		pq.push(e[id][i]);
	}
	node to;
	do{
		to=pq.top();
		pq.pop();
//		cout<<"to="<<to.to<<" w="<<to.w<<endl;
	}while(!pq.empty()&&used[to.to]==1);
	if(used[to.to]) return;
	ans+=to.w;
	findd(to.to);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	ll w;
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y),read(w);
		e[x].push_back({y,w});
		e[y].push_back({x,w});
	}
//	cout<<e[1].size()<<endl;
//	for(int i=0;i<e[1].size();i++){
//		cout<<e[1][i].to<<" "<<e[1][i].w<<endl;
//	}
//	puts("");
	bool flag=1;
	for(int i=1;i<=k;i++){
		read(a[i]);
		if(a[i]) flag=0;
		for(int j=1;j<=n;j++){
			read(f[i][j]);
		}
	}
//	pq.push(e[1][0]);
//	pq.push(e[1][1]);
//	pq.push(e[1][2]);
//	pq.push(e[4][1]);
//	pq.push(e[3][2]);
//	while(!pq.empty()){
//		node t=pq.top();
//		pq.pop();
//		cout<<t.w<<" "<<t.to<<endl;
//	}
//	puts("");
	if(flag) findd(1);
	else find(1);
	printf("%d\n",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4 
0 1 8 2 4
0 99 99 99 99

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4 
1 1 8 2 4
100 1 3 2 4

4 5 0
1 2 100
1 3 99
1 4 3
4 3 98
3 2 1000

7 10 1
1 2 1
1 3 1
1 4 1
2 5 2
2 6 2
3 6 2
3 7 2
4 7 2
5 6 1
6 7 1
0 99 99 99 2 99 99 1

*/
