#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long mod = 998244353;
int c[510],p[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string str;
	cin >> n >> m;
	cin >> str;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	bool ok = true;
	for(int i=0;i<n;i++){
		ok = false;
	}
	if(ok){
		long long ans = 1;
		for(int i=2;i<=n;i++){
			ans = ans*i%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n<=18){
		for(int i=1;i<=n;i++){
			p[i] = i;
		}
		long long ans = 0;
		do{
			int now = 0,opt = 1;
			for(int i=1;i<=n;i++){
				if(str[i-1] == '0' || now >= c[p[i]])
					now++;
				if(n-now < m){
					opt = 0;
					break;
				}
			}
			if(opt) ans = (ans+1)%mod;
		}while(next_permutation(p+1,p+n+1));
		printf("%lld",ans);
		return 0;
	}
	if(m == n){
		if(str.find('0')){
			printf("0");
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(c[i] == 0){
				printf("0");
				return 0;
			}
		}
		long long ans = 1;
		for(int i=2;i<=n;i++){
			ans = ans*i%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
