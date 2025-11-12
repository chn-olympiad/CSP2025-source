#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int mod=998244353;
int n, m;
int a[510];
int c[510];
char s[510];

int main(){
	
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	c[1]=s[0]-'1';
	for(int i=1; i<n; i++){
		c[i+1]=c[i]+s[i]-'0';
	}
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	ll ans=1;
	for(int i=1; i<n; i++){
		ans=(ans*i)%mod;
	}
	if(m==1){
		for(int i=0; i<n; i++){
			if(s[i]=='1'){
				for(int j=1; j<=n; j++){
					if(a[j]>i){
						ans=(ans+(ans*(n-j+1))%mod)%mod;
						break;
					}
				}
				break;
			}
		}
		cout << ans;
		return 0;
	}
	if(m==n){
		if(c[n]!=n){
			cout << 0;
			return 0;
		}
		for(int i=1; i<=n; i++){
			if(a[i]==0){
				cout << 0;
				return 0;
			}
		}
		ans=(ans*n)%mod; 
		cout << ans;
		return 0;
	}
	ans=(ans*n)%mod;
	cout << ans;
	return 0;
}
