#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+10;
const ll INF = LONG_LONG_MAX;
struct node{
	ll x,y;
	ll val;
}a[N],t[N];
ll n,m,k;
ll c[12],f[N];
ll d[12][N],tot,ans=INF,cnt;
vector < ll > v;
inline ll read(){
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		x = x*10+ch-'0';
		ch = getchar();
	}
	return x*f;
}
bool cmp(node x,node y){
	return x.val<y.val;
}
ll find(ll x){
	if(x==f[x]) return x;
	else return f[x] = find(f[x]);
} 
void solve(ll p){
	sort(t+1,t+tot+1,cmp);
	for(ll i=1;i<=n+k;i++){
		f[i] = i;
	}
	ll num = 0;
	for(ll i=1;i<=tot;i++){
		ll x = t[i].x;
		ll y = t[i].y;
		ll fx = find(x);
		ll fy = find(y);
		if(fx==fy) continue;
		else{
		//	cout<<t[i].x<<" "<<t[i].y<<" "<<t[i].val<<endl;
			num++;
			cnt+=t[i].val;
			f[fx] = fy;
		}
	}
	return ;
}
void dfs(ll u){
	if(u>k){
		ll len = v.size();
		cnt = 0;
		for(ll i=1;i<=m;i++){
			t[i] = a[i];
		}
		tot = m;
		for(ll i=0;i<v.size();i++){
			cnt += c[v[i]];
			for(ll j=1;j<=n;j++){
				t[++tot].x = v[i]+n;
				t[tot].y = j;
				t[tot].val = d[v[i]][j]; 
			}
		}	
		solve(n+v.size());
		ans = min(ans,cnt);
//		for(ll i=0;i<v.size();i++){
//			cout<<v[i]<<" ";
//		}
//		cout<<cnt<<endl;
		return ;
	}
	v.push_back(u);
	dfs(u+1);
	v.pop_back();
	dfs(u+1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();
	m = read();
	k = read();
	for(ll i=1;i<=m;i++){
		a[i].x = read();
		a[i].y = read();
		a[i].val = read();
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	if(k<=5){
		dfs(1);
		cout<<ans;
	}
	else{
		cnt = 0;
		for(ll i=1;i<=m;i++){
			t[i] = a[i];
		}
		tot = m;
		for(ll i=1;i<=k;i++){
			for(ll j=1;j<=n;j++){
				t[++tot].x = n+i;
				t[tot].y = j;
				t[tot].val = d[i][j];
			}
		}
		solve(n+k);
		ans = cnt;
		cout<<ans;
	}
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 0 2 4
0 1 0 2 4



*/
