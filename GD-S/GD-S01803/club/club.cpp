#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+5;
int n;
struct node{int a,b,c;}t[N];
ll sum;
void dfs(int id,int p1,int p2,int p3,ll res){
	if(p1*2>n||p2*2>n||p3*2>n) return;
	++id;
	if(id>n) return sum=max(sum,res),void();
	dfs(id,p1+1,p2,p3,res+t[id].a);
	dfs(id,p1,p2+1,p3,res+t[id].b);
	dfs(id,p1,p2,p3+1,res+t[id].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>t[i].a>>t[i].b>>t[i].c;
		sum=0;
		dfs(0,0,0,0,0);
		cout<<sum<<'\n';
	}
}
