#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
const int maxn = 510,mod = 998244353;
int f[maxn];
int c[maxn];
int p[maxn];
int ans;
//

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x == '1') f[i] = 1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n <= 10){
		for(int i=1;i<=n;i++) p[i] = i;
		do{
			int cnt = 0;
			int emp = 0;
			for(int i=1;i<=n;i++){
				if(f[i] == 0) cnt++;
				else{
					if(c[p[i]] <= cnt) cnt++;
					else emp++;
				}
			}
//			if(emp >= m){
//				for(int i=1;i<=n;i++) cout<<p[i];
//				cout<<'\n';
// 			}
			ans += (emp >= m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans%mod;
		return 0;
	}
	return 0;
}
