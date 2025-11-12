#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],l[510],c,f=1,mod=998244353,t;
char s[510];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	t=n;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		if(s[i]!='1'){
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0){
			t--;
		}
	}
	if(f||m==1){
		c=1;
		for(int i=1;i<=t;i++){
			c=(c*i)%mod;
		}
		cout << c;
		return 0;
	}
	
	return 0;
}