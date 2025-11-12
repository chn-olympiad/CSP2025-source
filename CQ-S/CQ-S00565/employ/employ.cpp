#include <bits/stdc++.h>
#define name "employ"
#define popcnt __builtin_popcount
using namespace std;
const int N=507,mod=998244353;
int f[(1<<18)+7][19],s[N],c[N],fa[N];
int main(){
	freopen(name".in","r",stdin);
	freopen(name".out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	char ch;
	for(int i=0;i<n;i++) cin>>ch,s[i]=(ch=='1');
	for(int i=0;i<n;i++) cin>>c[i];
	fa[0]=1;
	for(int i=1;i<=n;i++) fa[i]=1ll*fa[i-1]*i%mod;
	if(n<=18){
		f[0][0]=1;
		for(int i=0;i<(1<<n);i++) {
			int v=popcnt(i);
			for(int x=0;x<=min(v,m);x++) for(int j=((1<<n)-1)^i;j;j-=(j&-j)) if((f[i|(j&-j)][min(m,x+(s[v]&&v-x<c[__lg(j&-j)]))]+=f[i][x])>=mod) f[i|(j&-j)][min(m,x+(s[popcnt(i)+1]&&x<c[__lg(j&-j)]))]-=mod;
		}
		cout<<f[(1<<n)-1][m]<<'\n';
		return 0;
	}
	if(m==n){
		cout<<fa[n]<<'\n';
		return 0;
	}
	int sum=0;
	for(int i=0;i<n;i++) sum+=s[i];
	if(sum==n){
		
	}
	return 0;
}

//froepen("employ.cpp","r",stdin)
//freoepm("employ.out","w",stdin)
//CSP AK me
//rp+=inf
//#include <bits\stdc++.h>
//#inculde <bits/stdc++.h>
//freopen
//const int mod=998244853;
//qwq awa qaq
//queueforces 
//orz
//How to dp a permutation?????????
//qwq
//qwqwq
//qwqwqwq
//qwqwqwqwq
//qwqwqwqwqwq
//qwqwqwqwqwqwq
//qwqwqwqwqwqwqwq
//qwqwqwqwqwqwqwqwq
//qwqwqwqwqwqwqwqwqwq
//qwqwqwqwqwqwqwqwqwqwq
//qwqwqwqwqwqwqwqwqwqwqwq
