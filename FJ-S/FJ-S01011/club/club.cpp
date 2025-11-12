#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	
	freopen("club.in","r","std.in")
	freopen("club.out","w","std.out")
	
	int t;
	cin>>t;
	int sum=0;
	sort(a+1,a+t+1)
	for(int i=1;i<=n;i++){
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		sum+=a[1];
		sum+=b[1];
		sum+=c[1];
	}
	if(n%3==0) cout<<sum;
	else cout<<sum+a[2];
	
	
	return 0;
}
