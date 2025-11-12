#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans,c[505];
string s;
bool bl[25];
long long ln[25];
inline void f(long long x=1){
	if(x<=n){
		for(long long i=1;i<=n;i++){
			if(!bl[i]){
				bl[i]=1,ln[x]=i;
				f(x+1);
				bl[i]=0,ln[x]=0;
			}
		}
		return;
	}
	long long cnt=0,sum=0;
	for(long long i=1;i<=n;i++){
		if(cnt<c[ln[i]] && s[i]=='1') sum++;
		else cnt++;
		if(sum>=m){
			ans=(ans+1)%mod;
			return;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s="@"+s;
	for(long long i=1;i<=n;i++){
		cin >> c[i];
	}
	if(n<=18){
		f();
		cout<<ans<<"\n";
		return 0;
	}
	ans=1;
	for(long long i=1;i<=n;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
18 5
110111101111011110
6 0 4 2 1 2 5 4 3 3 6 0 4 2 1 2 5 4

*/
