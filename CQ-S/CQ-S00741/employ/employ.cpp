#include<bits/stdc++.h>
#define mod 998244353 
#define N 505
using namespace std;
int n,m,c[N];
string s;
int p[N];
void solve1(){
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0,w=0,res=0;
	while(1){
		int ff=0;
		w=0,res=0;
		for(int i=1;i<=n;i++){
			if(w<c[p[i]]&&s[i]=='1') res++;
			else w++;
		}
		if(res>=m) ans++;
		next_permutation(p+1,p+1+n);
		for(int i=1;i<=n;i++){
			if(p[i]!=i) ff=1;
		}
		if(!ff) break;
	}
	cout<<ans%mod;
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;s=" "+s;
	int hh=0;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=12) solve1();
	else cout<<0;
	
	return 0;
}
