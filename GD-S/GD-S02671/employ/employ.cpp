#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,MOD=998244353;
long long n,m,ans=1,ans2=1,c[N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	int k=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			k++;
		}
	}
	for(int i=2;i<=n-k;i++){
		ans=(ans*i)%MOD;
	}
	if(n-k<m){
		cout << 0;
	}else{
		if(k>0){
			for(int i=2;i<=k;i++){
				ans=(ans*i)%MOD;
			}
		}
		cout << ans;
	}
}
