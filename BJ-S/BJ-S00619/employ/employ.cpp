#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,a;
int sum=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(i=1;i<=n;i++) cin >> a;
    for(i=1;i<=n;i++){
        sum*=i;
        sum%=998244353;
    }
    cout << sum;
    return 0;
}
