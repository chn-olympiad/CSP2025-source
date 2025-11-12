#include<bits/stdc++.h>
using namespace std;
void file_init(){
#ifndef LOCAL
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	return;
}
void fast_read(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return;
}
int n,m;
string s;
const int N=510;
int cnt[N];
void read(){
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	return;
}
int dat[N];
int check(){
	int cnt=0,pas=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||cnt>=dat[i]){
			cnt++;
		}else{
			pas++;
			cnt=0;
		}
	}
	return pas>=m;
}
const int mod=998244353;
#define ll long long
ll solve(int x){
	if(x==n+1){
		return check();
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		if(cnt[i]){
			cnt[i]--;
			dat[x]=i;
			ans+=solve(x+1)*(cnt[i]+1)%mod;
			if(ans>=mod){
				ans-=mod;
			}
			cnt[i]++;
		}
	}
	return ans;
}
int main(){
	file_init();
	fast_read();
	read();
	cout<<solve(1);
	return 0;
}
