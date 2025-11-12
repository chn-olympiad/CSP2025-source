#include<bits/stdc++.h>

using namespace std;

const int N = 5*1e5+10;
#define int long long
int n,m,k;
struct p{
	int u,v,w;
}a[N];
int len;

void add(int u,int v,int w){
	a[++len].u = u;
	a[len].v = v;
	a[len].w = w;
}

bool cmp(p a,p b){
	return a.w<b.w;
}

long long fa[100001];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}
map<int,int> s;
int k1;
bool check(){
	for(int i = 1;i<=k1;i++){
		if(s[i]==0) return 0;
	}
	return 1;
}

signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	
	
	
	
	
	
	
	
	
	
	
	
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	k1 = n;
	for(int i = 1;i<=k;i++){
		int c;
		cin>>c;
		for(int j = 1;j<=k1;j++){
			int a;
			cin>>a;
			add(++n,j,a+c);
			add(j,n,a+c);
		}
	}
	sort(a+1,a+1+len,cmp);
	int ans = 0,cnt = 0;
	for(int i = 1;i<=n;i++) fa[i] = i;
	for(int i = 1;i<=len;i++){
		int s1 = find(a[i].u);
		int s2 = find(a[i].v);
		if(s1!=s2){
			fa[s1] = s2;
			s[s1]++;
			s[s2]++;	
			ans+=a[i].w;
		}
		if(check()) break;
	}
	cout<<ans;
	return 0;
}
//bye bye qqq
