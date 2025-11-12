#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,mod = 998244353;
#define int long long
int n,m;
string s;
int vis[N],a[N],b[N],c[N];
int res=0;
int jie(int x){
	if(x == 1){
		return 1;
	}
	return x%mod*jie(x-1)%mod;
}
bool check(int len){
	int res=0;
	for(int i=1;i<=len;i++){
		a[i] = b[c[i]];
//		cout << c[i] << ' ';
	}
//	cout << '\n';
	for(int i=1;i<=len;i++){
		if(s[i] == '0'){
			a[i] = 0;
			for(int j=i;j<=len;j++){
				a[j]--;
			}
		}
	}
	for(int i=1;i<=len;i++){
		if(a[i] <= 0 and s[i] != '0'){
			for(int j=i;j<=len;j++){
				a[j]--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i] > 0){
			res++;
		}
//		cout << a[i] << ' ';
	}
//	cout << '\n';
	return res>=m;
}
void dfs(int cur){
	if(cur == n){
		if(check(n)){
			res++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			c[cur+1]=i;
			dfs(cur+1);
			vis[i]=0;
		}
	}
	return;
}
void work(){
	cin >> n >> m;
	cin >> s;
	s=' '+s;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i] != '1'){
			f=0;
		}
	}
	if(f){
		cout << jie(n);
		return;
	}
	dfs(0);
	cout << res; 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}

