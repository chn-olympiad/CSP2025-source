#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5005;
int a[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	int mx=-1e9;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>mx) mx=a[i];
		cnt+=a[i];
	}
	if(n<=3){
		if(n<3) cout<<0;
		else{
			if(cnt>2*mx) cout<<1;
			else cout<<0;
		}
	}
	if(mx==1){
		cout<<0;
	}
	return 0;
}
