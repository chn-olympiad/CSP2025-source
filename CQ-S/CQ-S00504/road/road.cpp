#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int sum=0;
int cnt[20][10100];
struct noo{
	int a;
	int b;
	int zhi;
	bool operator<(const noo &ot)const{
		return zhi>ot.zhi;
	}
};
priority_queue<noo> q,q2;
int fa[10100];
void dd(int mm){
	for(int i=1;i<=mm;i++){
		fa[i]=i;
	}
}
int who_fa(int id){
	if(fa[id]==id){
		return id;
	}
	return (fa[id]=who_fa(fa[id]));
}
int ans=0;
int ans_end=0;
int zdl(int nn){
	dd(nn);
	ans=0;
	while(!q2.empty()){
		noo now=q2.top();
		q2.pop();
		if(who_fa(now.a)!=who_fa(now.b)){
			ans+=now.zhi;
			fa[who_fa(now.a)]=who_fa(now.b);
		}
		if(ans_end!=-1&&sum+ans>ans_end){
			return -1;
		}
	}
	int flag=who_fa(1);
	for(int i=2;i<=nn;i++){
		if(flag!=who_fa(i)){
			return -1;
		}
	}
	return ans;
}
int ff[20];
void dfs(int id){
	if(id>k){
		q2=q;
		sum=0;
		int iid=0;
		for(int i=1;i<=k;i++){
			if(ff[i]==1){
				iid++;
				sum+=cnt[i][0];
				for(int j=1;j<=n;j++){
					q2.push({n+iid,j,cnt[i][j]});
				}
			}
			if(ans_end!=-1&&sum>ans_end){
				return ;
			}
		}
		int nnn= zdl(n+iid);
		if(nnn!=-1){
			if(ans_end==-1) ans_end=nnn+sum;
			else ans_end=min(ans_end,nnn+sum);
		}
		return ;
	}
	ff[id]=1;
	dfs(id+1);
	ff[id]=0;
	dfs(id+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		q.push({a,b,c});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>cnt[i][j];
		}
	}
	q2=q;
	ans_end=zdl(n);
	dfs(1);
	cout<<ans_end;
	return 0;
}
