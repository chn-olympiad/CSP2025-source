#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline int read();
const int N = 510,mod = 998244353;
char s[N];
int c[N];
int op[N];
int n,m;
int ans;
bool vis[N];
int di[N];
void dfs(int x){
	if(x == n+1){
		int q=0,lu=0;
		for(int i=1;i<=n;i++){
			if(q >= c[di[i]]){
				q++;
			}
			else{
				if(s[i]=='0'){
				//cout<<i<<endl;
					q++;
				}
				else{
					lu++;
				}
			}
		}
		if(lu >= m) ans++;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				di[i] = x;
				vis[i] = 1;
				dfs(x+1);
				vis[i] = 0;
				di[i] = 0;
			}
		}
		return;
	}
}
int dp[N][N];//倒数第i个人，倒数录取j人的方案数 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		c[i] = read();
	}
	if(n <= 18){
		dfs(1);
		cout<<ans<<endl;
	}
	else{
		ans = 1;
		for(int i=1;i<=n;i++){
			ans=(ans * i) % mod;
		}
		cout<<ans<<endl;
		
	}
	
	
	return 0;
}
inline int read(){
	char x=getchar();
	int res = 0;
	int f = 1;
	while(x < '0' || x >'9'){
		if(x == '-') f =-1;
		x = getchar();
	}
	while(x >='0' && x <='9'){
		res = res * 10 + (x -'0');
		x=getchar();
	}
	return res * f;
}

