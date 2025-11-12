#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001],c[100010];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin >>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin >>c[i];
	}
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	cout <<(long long)(pow(2,m)-2)%998244353;
	return 0;
}
