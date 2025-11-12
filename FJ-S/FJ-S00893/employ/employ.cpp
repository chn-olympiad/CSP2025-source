#include<bits/stdc++.h>
#define N 998244353
using namespace std;
int n,m,a[100001];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;long long ans=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=m;i++){
		ans*=i;ans%=N;
	}
	cout<<ans;
	return 0;
}

