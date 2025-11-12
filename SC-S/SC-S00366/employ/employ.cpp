#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353;
int a[550];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) k++;
	}
	int sum=1;
	for(int i=1;i<=n-k;i++) sum*=i,sum%=mod;
	cout<<sum;
	return 0;
}