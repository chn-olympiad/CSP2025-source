#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long md=998244353,ans=1;
	int n,m,c[100005];
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=n;i>m;i--) ans*=i;
	cout<<ans%md;
	return 0;
}

