#include <bits/stdc++.h>
#define int long long
constexpr int maxn=514;
constexpr int mod=998244353;
using namespace std;
int n, m, c[maxn], p[maxn], allans=0, tmp, tmp2;
string s;
bool flag=true;
int A(int a, int b){
	int res=1;
	for (int i=a-b+1; i<=a; i++){
		res=(res*i)%mod;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for (int i=0; i<n; i++){
		if (s[i]=='0') flag=false;
	}
	cout<<flag<<"\n";
	tmp=n;
	for (int i=1; i<=n; i++){
		cin>>c[i];
		if (c[i]==0) tmp--;
		p[i]=i;
	}
	tmp2=n-tmp;
	if (tmp<m){
		cout<<0<<"\n";
		return 0;
	}
	if (flag==false&&m==n){
		cout<<0<<"\n";
		return 0;
	}
	if (flag){
		cout<<A(n, n)<<"\n";
		return 0;
	}
	do{
		int ans=0;
		for (int i=1; i<=n; i++){
			if (s[i-1]=='1'){
				if (c[p[i]]>ans){
					continue;
				}
			}
			ans++;
		}
		if (n-ans>=m) allans=(allans+1)%mod;
	} while (next_permutation(p+1, p+n+1));
	cout<<allans<<"\n";
}
