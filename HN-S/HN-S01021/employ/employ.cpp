#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 504;
const int mod = 998244353;
ll ans;
int n,m; 
string s;
int a[maxn];
struct nod{
	int num;
	int c;
}aa[maxn]; 
bool b[maxn];
int d[maxn];
bool pd(){
	ll cnt = 0;
	ll out = 0;
	for(int i = 1;i <= n; i++){
		if(out >= aa[i].c){
			++out;
			continue;
		}
		else if(a[d[i]] == 1){
			//This exam is hard
			++out;
			continue;
		}
		else{
			++cnt;
		}
	}
	if(cnt >= m){
		return 1;
	}
	else return 0;
}
void dfs(int depth){
	if(depth >= n){
		if(pd() == 1){
			++ans;
			ans %= mod;
		}
	}
	for(int i = 1;i <= n; i++){
		if(!b[i]){
			d[depth] = i;
			b[i] = 1;
			dfs(depth+1);
			b[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i = 1;i <= n; i++){
		a[i] = s[i-1] - '0';
	}
	for(int i = 1;i <= n; i++){
		scanf("%d",&aa[i].c);
		aa[i].num = i;
	}	
	//暴力直接500!
	//又因为#1#2n <= 10
	//10! = 3631200 < 10^8
	//so 暴力出奇迹
	//但是18!肯定会爆
	//so 本题最多10分
	dfs(0);
	printf("%lld\n",ans);
	return 0; 
}
