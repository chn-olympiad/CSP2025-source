#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,s[N],c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		char z;
		cin>>z;
		s[i]=z-'0';
		if(s[i]==0) f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(f==0){
		int cnt=0,s1=1,s2=1;
		for(int i=n;i>=1;i--){
			cnt++;
			s1*=i;
			s2*=cnt;
			if(cnt==m) break;
		}
		cout<<(s1/s2)%mod;
		return 0;
	}
	return 0;
}
