#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define pii pair<int,int>
#define endl '\n'
const int N = 1e5+5;
const int base = 1e9+7;
const int mod = 998244353;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){ x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,cnt,ans;
bool sub_A=true;
int s[N],c[N];
int lst[N],vis[N];
void check(){
	int cntt = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(i-cntt-1>=c[lst[i]] || s[i]==0) continue;
		cntt ++;
		if(cntt >= m){
			ans ++;
			return;
		}
	}
	return;
}
void dfs(int step){
	if(step == n+1){
		check();
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!vis[i]){
			vis[i]=1;
			lst[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();
	m = read();
	string str ;
	cin >> str;
	int len = str.size();
	for(int i = 0 ; i <  len; i ++){
		s[i+1]=str[i]-'0';
		sub_A = sub_A&&s[i+1];
	}
	for(int i = 1 ; i <= n ; i ++){
		cin >> c[i];
		cnt += (c[i]>0?1:0);
	}
	if(sub_A){
		if(cnt<m) cout << "0\n";
		else{
			ans = 1;
			for(int i = cnt,j=1;j<=m;j++,i--){
				ans = (ans*i)%mod;
			}
			for(int i = n-cnt;i > 1 ; i --){
				ans = (ans*i)%mod;
			}
			cout << ans << endl;
		}
		return 0;
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}

