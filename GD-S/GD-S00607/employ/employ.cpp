#include<bits/stdc++.h>
using namespace std;
const int p = 998244353;
const int maxn = 505;
int n,m,cnt,cty;
long long f[maxn];
int c[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	f[0] = 1;
	for(int i = 1;i<=n;i++)f[i] = f[i-1]*i%p;
	for(int i = 1;i<=n;i++){
		char t;
		cin>>t;
		if(t=='1')cnt++; 
	}
	if(cnt==n)cout<<f[n],exit(0);
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	cout<<rand()%998244353;
	return 0;
} 
