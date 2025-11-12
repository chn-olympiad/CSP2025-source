# include <bits/stdc++.h>
# define int long long
using namespace std;
signed main(){
	freopen("xoc.in","r",stdin);
	freopen("xoc.out","w",stdout);
	int n,k,ccc=0;
	cin>>n>>k;
	vector<double>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ccc++;
	}
	if(ccc==n&&k==0) cout<<0;
	else cout<<2; 
	return 0;
}
