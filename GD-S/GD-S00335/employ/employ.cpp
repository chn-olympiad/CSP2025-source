#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,Mod = 998244353;
string s;
ll c[505];
ll a[505];
ll jie[505];
bool vis[505];
ll ans = 0;
bool check_sub1(){
	ll cnt = 0 , res = 0;
	for(int i=1;i<=n;i++){
		if(s[i-1] == '1' && cnt < a[i]) res++;
		else cnt++;
	}
	return res >= m;
}
void p(ll id){
	if(id == n + 1){
		ans += check_sub1(); 
		ans %= Mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		a[id] = c[i];
		p(id+1);
		vis[i] = 0;
	}
}
ll d[20] , tot = 0;
ll e[20];
ll ansB = 0;
ll getsubB(ll v){
	ll j = n+1;
	ll res = 1;
	for(int i=v;i>=1;i--){
		while(e[i] - i < c[j-1] && j - 1 >= 1) j--;
		res = res * (n - j + 1 + i - v) % Mod;
	}
	return res * jie[n - v] % Mod;
}
void CsubB(ll id,ll ch,ll v,ll u){
	if(ch == v){
		ansB += getsubB(v);
		ansB %= Mod;
		//if(v != 5) return ;
		//for(int i=1;i<=v;i++) cout<<e[i]<<" ";
		//cout<<endl; 
		return ;
	}
	if(id == u + 1) return ;
	CsubB(id+1,ch,v,u);
	e[ch+1] = d[id];
	CsubB(id+1,ch+1,v,u); 
}
void subB(){
	for(int i=0;i<s.size();i++){
		if(s[i] == '1') d[++tot] = i + 1;
	}
	//for(int i=1;i<=tot;i++) cout<<d[i]<<" ";
	ansB = 0;
	CsubB(1,0,m,tot);
	//ans = m * ansB;
	ans = ansB;
	//cout<<ans<<endl;
	for(int i=m+1,f=-1,z=m+1;i<=n;z=z*(i+1)%Mod,i++,f=-f){
		ansB = 0;
		CsubB(1,0,i,tot);
		ans += f * (z-1) * ansB;
		ans = (ans + Mod) % Mod;
		//cout<<ans<<" "<<f<<" "<<z<<" "<<ansB<<endl;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll sum = 0;
	jie[0] = 1;
	for(int i=1;i<=n;i++) jie[i] = jie[i-1] * i % Mod;
	for(int i=0;i<s.size();i++){
		if(s[i] == '1') sum++;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	if(n <= 10){
		p(1);
		cout<<ans % Mod<<endl;
		return 0;
	}
	if(sum < m){
		cout<<0<<endl;
		return 0;
	}
	if(sum <= 18){
		subB();
		cout<<ans<<endl;
		return 0;
	}
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
