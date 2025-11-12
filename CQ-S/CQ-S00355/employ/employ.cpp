#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
#define il inline
#define re register
using namespace std;
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(48^ch);
		ch=getchar();
	}
	return x*f;
}
const ll MOD=998244353;
ll c[500][500];
ll C(ll n,ll r){
	if(r==1) return n;
	ll ans=0;
	if(c[n-1][r]!=0&&n-1>=r){
		ans+=c[n-1][r];
		ans%=MOD;
	}
	else if(n-1>=r){
		ans+=C(n-1,r)%MOD;
	}
	if(c[n-1][r-1]!=0){
		ans+=c[n-1][r-1];
		ans%=MOD;
	}
	else{
		ans+=C(n-1,r-1)%MOD;
	}
	c[n][r]=ans%MOD;
	return ans%MOD;
}
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	int n,m;
	string s;
	n=read(),m=read();
	if(m>n){cout<<0;return 0;}
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]==0) cnt++;
	}
	ll ans=C(n,n-cnt)%MOD;
	cout<<ans;
	return 0;
}
/*
100 47 
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
