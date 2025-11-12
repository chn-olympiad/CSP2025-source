#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=1e4+10,M=1e6+10;
int f[N],c[13],kl[15],cnt[N];
bool vis[14];
struct ayin{
	int fr,to,w;
}s[M];
struct evil{
	int x,id;
}a[14][N];
vector<ayin> t;
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool cmp(ayin x,ayin y){
	return x.w<y.w;
}
bool nc(evil x,evil y){
	return x.x<y.x;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>s[i].fr>>s[i].to>>s[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];kl[i]=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j].x;
			a[i][j].id=1;
		}
	}
	sort(s+1,s+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int x=s[i].fr,y=s[i].to,p=s[i].w;
		if(find(x)!=find(y)){
			f[find(x)]=find(y);
			ans+=p;
			t.push_back(s[i]);
		}
	}
	if(!k){
		cout<<ans<<"\n";
		return 0;
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=k;i++) sort(a[i]+1,a[i]+n+1,nc);
	sort(t.begin(),t.end(),cmp);
	for(int i=0;i<t.size();i++) cnt[t[i].fr]++,cnt[t[i].to]++;
	for(int i=t.size()-1;i>=0;i--){
		int x=t[i].fr,y=t[i].to,p=t[i].w,id=-1;
		if(x>y) swap(x,y);
		for(int j=1;j<=k;j++){
			if(vis[j]){
				if(a[j][kl[j]].x<p) p=a[j][kl[j]].x,id=j;
			}else{
				if(kl[j]+1<=n){
					if(c[j]+a[j][kl[j]].x+a[j][kl[j]+1].x<p){
						p=c[j]+a[j][kl[j]].x+a[j][kl[j]+1].x,id=j;
					}
				}
			}
		}
//		cout<<t[i].w<<" "<<id<<" "<<p<<"\n"; 
		if(id==-1) continue;
		int u=kl[id];
		if(vis[id]){
			if(cnt[x]==1&&cnt[y]==1) continue;
			if(cnt[x]==1){
				if(a[id][u].id!=x) continue;
			}
			if(cnt[y]==1){
				if(a[id][u].id!=y) continue;
			}
		}else{
			if(a[id][u].id>a[id][u+1].id) swap(a[id][u].id,a[id][u+1].id);
			if(cnt[x]==1&&cnt[y]==1){
				if(a[id][u].id!=x&&a[id][u+1].id!=y) continue;
			}
			if(cnt[x]==1){
				if(a[id][u].id!=x){
					if(a[id][u+1].id!=x) continue;
				}
				if(a[id][u+1].id!=x){
					if(a[id][u].id!=x) continue;
				}
			}
			if(cnt[y]==1){
				if(a[id][u].id!=y){
					if(a[id][u+1].id!=y) continue;
				}
				if(a[id][u+1].id!=y){
					if(a[id][u].id!=y) continue;
				}
			}
		}
		ans=ans-t[i].w+p;
		if(vis[id]) kl[id]++;
		if(!vis[id]) kl[id]+=2;
		vis[id]=1;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 5
4 2 6
4 3 4
1 1 8 2 4
100 1 3 2 4
*/ 

