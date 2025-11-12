#include <bits/stdc++.h>
using namespace std;
const int N=1e5,mod=998244353;
int c[N];
bool q[N];
bool v[N];
int n,m;
string s;
int ans=0;
void init(){
	for(int i=1;i<=n;i++) q[i]=int(s[i]-'0');
}
void solv(int pos,int t,int pass){
	if(pos>n) return;
	if(t>=m) {ans++;ans%=mod;return ;}
	if(c[pos]<=pass) return ;
	if(q[pos]) t++;
	else pass++;
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		solv(i,t,pass);
		v[i]=0;
	}
}
//10 5
//1101111011
//6 0 4 2 1 2 5 4 3 3
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	init();
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) {
		v[i]=1;solv(i,0,0);v[i]=0;
	}
	cout<<ans;
	return 0;
} 