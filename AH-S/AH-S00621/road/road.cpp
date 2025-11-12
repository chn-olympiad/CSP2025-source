#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,k;
vector<pair<int,pair<int,int> > > e;
vector<pair<int,pair<int,int> > > e1;
int nn;
int fa[200000+5];
int ret;
int find(int k){
	return fa[k]==k?fa[k]:fa[k]=find(fa[k]);
}
void kruskal(){
	for(int i=1;i<=200000;i++) fa[i]=i;
	sort(e.begin(),e.end());
	for(auto i:e){
		if(find(i.second.first)==find(i.second.second)) continue;
		else fa[find(i.second.first)]=find(i.second.second),ret+=i.first;
	}
}
void kruskal1(){
	for(int i=1;i<=200000;i++) fa[i]=i;
	sort(e1.begin(),e1.end());
	for(auto i:e1){
		if(find(i.second.first)==find(i.second.second)) continue;
		else fa[find(i.second.first)]=find(i.second.second),ret+=i.first;
	}
}
vector<int> v;
int c[10][100000+5];

void dfs(int step,int lst){
		int cnt=0;
		while(e1.size()) e1.pop_back();
		for(int i=1;i<=m;i++) e1=e;
		for(auto i:v){
			cnt+=c[i][0];
			for(int j=1;j<=n;j++) e1.push_back(make_pair(c[i][j],make_pair(n+i,j)));
		}
		kruskal1();
		ret=min(ret,cnt);
		//for(int i
	if(step>k) return ;
	for(int i=lst+1;i<=k;i++){
		v.push_back(i);
		dfs(step+1,i);
		v.pop_back();
	}
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	nn=n+k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e.push_back(make_pair(c,make_pair(a,b)));
	}
	if(k<=5){
		ret=2147483647;
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				cin>>c[i][j];
			}
		}dfs(1,0);
		cout<<ret;
		return 0;
	}
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			int a;
			cin>>a;
			if(j) e.push_back(make_pair(a,make_pair(j,n+i)));
		}
	}
	kruskal();
	cout<<ret;
    return 0;
}
