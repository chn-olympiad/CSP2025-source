#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MOD 998244353
int n,m;
char s[MAXN];
int c[MAXN];
int p[MAXN];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	m=n-m;
	int cc=0;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		cc+=(s[i]=='1');
		p[i]=i;
	}
	for(int i=1;i<=n;++i)cin>>c[i];
	long long sum=0;
	do{
		int tot=0;
		for(int i=1;i<=n;++i){
			int j=p[i];
			if(s[i]=='0'||c[j]<=tot)++tot;
		}
		if(tot<=m){
			++sum;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<sum<<'\n';
}
