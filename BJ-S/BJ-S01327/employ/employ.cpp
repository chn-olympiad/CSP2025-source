#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;
int n,m;
ll jc[505],s[505],tong[505];
char c[505];
bool check(){
	int rec=0,js=0;
	for(int i = 1;i<=n;++i){
		if(c[i]=='0'||js >= s[i]){
			js++;
		}else rec++;
	}
	//cout<<'#'<<rec<<' ';
	return rec>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i = 1;i<=n;++i){
		cin>>s[i];
		tong[s[i]]++;
	}
	jc[0]=1;
	for(int i = 1;i<=n;++i)jc[i]=jc[i-1]*i%MOD;
	int ways = 1;
	for(int i = 1;i<=n;++i){
		ways = ways*jc[tong[i]]%MOD;
	}
	sort(s+1,s+n+1);
	ll ans=0;
	do{
		if(check())ans++;
	}while(next_permutation(s+1,s+n+1));
	cout<<ways*ans%MOD;
	return 0;
}
