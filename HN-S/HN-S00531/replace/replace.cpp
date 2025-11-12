//看都看不懂  
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5, M = 2e6+5;
int n,q;
string a[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("repalce.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++) cin>>a[i][1]>>a[i][2];
	while(q--){
		int ans = 0;
		string x,y;
		cin>>x>>y;
		string xa = "",xb = "";
		int l = 0, r = 0;
		for(int i = 0;i < x.size();i++){
			if(x[i] != y[i] && !l) l = i;
			if(x[i] == y[i] && x[i-1] != y[i-1]) r = i;
		}
		for(int j = l;j <= r;j++){
				xa = xa+x[j];
				xb = xb+y[j];
		}
		for(int i = 1;i <= n;i++){
			if(a[i][1] == x && a[i][2] == y) ans++;
			if(a[i][1] == xa && a[i][2] == xb) ans++;
		}
		cout<<ans;
	}
	return 0;
}

