#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=507;
int n,m,a[N];
string s;

ll A(int x,int y){
	ll res=1;
	for(ll i=x;i>x-y;i--) res=(res*i)%mod;
	return res;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out","w",stdout);
	int cnt=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.size();i++){
		cnt+=(s[i]=='1');
	}
	if(cnt==n) cout<<A(n,n)<<"\n";
	else if(n-cnt<m) cout<<0<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
