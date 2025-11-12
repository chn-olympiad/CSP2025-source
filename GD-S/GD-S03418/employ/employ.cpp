#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505,M = 998244353;
int n,m,c[N],len,p[N],ans;
string s;
bool sp = true;

void brute(){
	s = " "+s;
	for(int i=1;i<=n;i++) p[i] = i;
	do{
		int cnt = 0,tot = 0;
		for(int i=1;i<=n;i++){
			if(cnt<c[p[i]] && s[i]=='1') tot++;
			else cnt++;
		}
		if(tot>=m) ans++;
		ans%=M;
	} while(next_permutation(p+1,p+1+n));
	cout<<ans;
}
void solve(){
	brute();
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	len = s.size();
	int tmp = 0;
	for(int i=0;i<len;i++) tmp += s[i]-'0';
	if(tmp<m){
		cout<<0;
		return 0;
	}
	else if(n<=10) brute();
	else solve();
	return 0;
}
