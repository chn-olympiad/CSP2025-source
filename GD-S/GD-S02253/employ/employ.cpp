#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10,P=998244353;
int n,m,a[N],s[N],p1,p2;
string S;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> S;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=S[i-1]-'0';
		p1+=(s[i]==1);
		p2+=(a[i]==0);
	}
	if (p1<m||n-p2<m){
		cout << 0;
		return 0;
	}
	if (p1==n){
		int res=1;
		for (int i=1;i<=n;i++){
			res=res*i%P;
		}
		cout << res;
		return 0;
	}
}
