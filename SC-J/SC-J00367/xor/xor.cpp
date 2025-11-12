#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=5e5 + 5;
int n,k;
struct ra{
	int l,r;
};
vector<ra> ac;
int mx=0,acs;
int vis[N];
void dfs(int s,int d){
	mx=max(mx,s);
	if(d >= acs){
		return;
	}
	dfs(s,d + 1);
	for(int i=ac[d].l;i <= ac[d].r;i++){
		if(vis[i] != 0){
			return;
		}
	}
	for(int i=ac[d].l;i <= ac[d].r;i++){
		vis[i]++;
	}
	dfs(s + 1,d + 1);
	for(int i=ac[d].l;i <= ac[d].r;i++){
		vis[i]--;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool f=true;
	int fa=0;
	cin >> n >> k;
	vector<int> a(n + 5);
	vector<int> qzh(n + 5);
	for(int i=1;i <= n;i++){
		cin >> a[i];
		qzh[i]=a[i] ^ qzh[i - 1];
		if(a[i] > 1){
			f=false;
		}
		fa+=a[i];
	}
	if(f){
		if(k == 1){
			cout << fa; 
		} else{
			int cnt=0;
			for(int i=1;i <= n;i++){
				if(a[i] == 0){
					cnt++;
				} else{
					if(a[i + 1] == 1){
						cnt++;
						i++;
					}
				}
			}
			cout << cnt;
		}
	} else{
		for(int i=1;i <= n;i++){
			for(int j=i;j <= n;j++){
				int t=qzh[j] ^ qzh[i - 1];
				if(t == k){
					ra t;
					t.l=i;
					t.r=j;
					ac.push_back(t);
				}
			}
		}
		acs=ac.size();
		dfs(0,0);
		cout << mx;
	}
	return 0;
}