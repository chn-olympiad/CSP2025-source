#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
int a[100005];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
