#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,k,f[10010];
bool bk[10010]={0};
vector<pair<int,int> > a[10050];
int find_fa(int x){
	return f[x]==0?x:f[x]=find_fa(x);
}
int kul(vector<bool> num){
	memset(f,0,sizeof(f));
	priority_queue<pair<int,pair<int,int> > > q;
//	for(int i=0;i<num.size();i++){
//		int nw=num[i];
//		for(int j=0;j<v[nw].size();j++){
//			q.push({-v[nw][j].second,{nw,v[nw][j].first}});
//		}
//	}
	for(int i=0;i<a[1].size();i++){
		if(num[a[1][i].first]==1) q.push({-a[1][i].second,{1,a[1][i].first}});
	}
	int ans=0;
	bool b[10050]={0};
	b[1]=1;
	while(!q.empty()){
		int u=q.top().second.first,v=q.top().second.second,w=-q.top().first;
//		cout<<u<<" "<<v<<"\n";
		q.pop();
		if(b[v]==1) continue;
		b[v]=1;
		ans+=w;
		for(int i=0;i<a[v].size();i++){
			if(num[a[v][i].first]==1&&b[a[v][i].first]==0) q.push({-a[v][i].second,{v,a[v][i].first}});
		}
	}
	return ans;
}
int ans=1e9+7;
void solve(vector<bool> num,int x){
	if(x>k){
		ans=min(kul(num),ans);
		return;
	}
	if(bk[x]==1){
		num.push_back(1);
		solve(num,x+1);
		return;
	}
	num.push_back(1);
	solve(num,x+1);
	num.pop_back();
	num.push_back(0);
	solve(num,x+1);
	num.pop_back();
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	int c[20];
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	bool b=0;
	for(int i=1;i<=k;i++){
		int w,c;
		c=read();
		if(c>0) b=1;
		else bk[i]=1;
		for(int j=1;j<=n;j++){
			w=read();
			a[n+i].push_back({j,w});
			a[j].push_back({n+i,c+w});
		}
	}
	vector<bool> num;
	if(b==0){
		for(int i=0;i<=n+k;i++){
			num.push_back(1);
		}
		cout<<kul(num);
		return 0;
	}
	for(int i=0;i<=n;i++){
		num.push_back(1);
	}
	solve(num,1);
	cout<<ans;
	return 0;
}
