#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[505],p[505],c[505][505],mod=998244353,q[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int sum=0;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		sum+=s[i];
	}
	int cnt=n;
	for(int i = 1;i <= n;i++){
		cin >> p[i];
		if(p[i]==0){
			cnt--;
		}
	}
	for(int i = 0;i <= 500;i++){
		c[i][0]=c[i][i]=1;
		for(int j = 1;j < i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
	q[0]=1;
	for(int i=1;i <= 500;i++){
		q[i]=q[i-1]*i;
		q[i]%=mod;
	}
	if(sum==n){
		if(cnt<m){
			cout << 0 << endl;
			return 0;
		} 
		cout << c[cnt][m]*q[n-m] << endl;
		return 0; 
	}
	cout << 0 << endl;
	return 0;
}
