#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,a[N],sum,nu=1;
char c[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(c+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(c[i]=='1')sum++;
	if(sum<m){
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n;i++){
		nu*=i;
		nu%=mod;
	}
	cout<<nu%mod;
	return 0;
}
