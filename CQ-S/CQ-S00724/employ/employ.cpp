#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int c[5050][5050];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string a;
	cin>>n>>m>>a;
	if(m==n){
		for(int i=0;i<=a.length();i++){
			if(a[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	else{
		c[0][0]=1;
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				c[i][j]%=998244353;
			}
		}
		cout<<c[n+1][m+1];
	}
	return 0;
}
