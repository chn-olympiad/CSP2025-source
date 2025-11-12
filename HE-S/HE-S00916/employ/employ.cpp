//May all the beauty be blessed.
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int mod=998244353;
int n,m;
int c[1010],a[1010];
bool v[1010];
bool f1=1;

void sol(){
	int res=1;
	for(int i=1;i<=n;i++){
		res*=i;
		res%=mod;
	}
	cout<<res;
}
bool check(){
	int sum=0,d=0;
	for(int i=1;i<=n;i++){
		if(v[i]==0) d++;
		else if(c[a[i]]<=d) d++;
		else sum++;
	}
	
	return (sum>=m);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		if(ch=='1') v[i]=1;
		else f1=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(m==n&&f1==0) cout<<0;
	else if(f1) sol();
	else if(n<=10){
		int sum=1,ans=0;
		for(int i=1;i<=n;i++) a[i]=i,sum*=i;
		sum--;
		if(check()) ans++;
		
		while(sum--){
			next_permutation(a+1,a+n+1);
			if(check()) ans++;
		}
		
		cout<<ans%mod;
	}

}
/*

*/


