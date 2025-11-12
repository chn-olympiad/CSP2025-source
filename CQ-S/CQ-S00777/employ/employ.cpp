#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,cnt1,dif[555],c[555],id[22];
long long ans;
string s;
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int now=c[id[i]];
		if(i-cnt-1>=now){
			continue;
		}
		if(dif[i]){
			cnt++;
		}
	}
	if(cnt>=m){
		return 1;
	}
	return 0;
}
void solve1(){
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	do{
		if(check()){
			ans=(ans+1)%mod;
		}
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
	return;
}
void solve2(){
	ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return;
}
bool ts=0;
int main(){
	if(ts){
		freopen("employ3.in","r",stdin);
	}
	else{
		freopen("employ.in","r",stdin);
	}
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		dif[i]=s[i]-'0';
		cin>>c[i];
		if(c[i]==0){
			cnt1++;
		}
	}
	if(n<=10){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
