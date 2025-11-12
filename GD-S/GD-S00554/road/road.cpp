#include<bits/stdc++.h>
#define int long long
using namespace std;

struct road{
	int start,to;
	int cost;
};

int UpC[12];
int UpNR[12][10010];


bool cmp(road a,road b){
	return a.cost > b.cost;	
}
int fa[10010];
int n,m,k;
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}

void connect(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx != fy)
		fa[fy] = fx;
}

int Kustral(vector<road> l){
	int ans = 0;
	for(int i=1;i<=n;i++)fa[i] = i;
	sort(l.begin(),l.end(),cmp);
	for(int i=0;i<l.size();i++){
		road x = l[i];
		int st = find(x.start);
		int en = find(x.to);
		if(st != en){
			ans += x.cost;
			connect(st,en);
		}
	}
	return ans;
}

bool CA = 1;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m>>k;
	vector<road> roa(m);
	for(int i=0;i<m;i++){
		cin>>roa[i].start>>roa[i].to>>roa[i].cost; 
	}
	if(k == 0)cout<<Kustral(roa);
	return 0;
}
