//GZ-S00439 遵义市南白中学 邹子奥 
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int T;
int n;
ll k[N][4];
map<ll,ll>m;
ll ans;
ll turn(int x,int a,int b,int c){
	ll res = 0;
	res = res*10 + (ll)x;
	res = res*10 + (ll)a;
	res = res*10 + (ll)b;
	res = res*10 + (ll)c;
	return res;
}
ll Max(ll a,ll b){
	if(a>b) return a;
	else return b;
}
ll dfs(int x,int a,int b,int c){
	if(x==n+1){
		return 0;
	}
	if(a+b+c>n){
		return 0;
	}
	if(m[turn(x,a,b,c)]) return m[turn(x,a,b,c)];
	ll ch1 = 0,ch2 = 0,ch3 = 0;
	if(a+1<=n/2){
		ch1 = dfs(x+1,a+1,b,c)+k[x][1];
	}
	if(b+1<=n/2){
		ch2 = dfs(x+1,a,b+1,c)+k[x][2];
	}
	if(c+1<=n/2){
		ch3 = dfs(x+1,a,b,c+1)+k[x][3];
	}
	m[turn(x,a,b,c)] = Max(ch1,Max(ch2,ch3));
	return m[turn(x,a,b,c)];
}
void work(){
	memset(k,0,sizeof(k));
	m.clear();
	ans = 0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>k[i][1]>>k[i][2]>>k[i][3];
	cout<<dfs(1,0,0,0)<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
