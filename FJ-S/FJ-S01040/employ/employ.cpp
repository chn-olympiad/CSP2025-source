#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int MOD=998244353;
int n,m;
string s;
int a[N];
int jc(int x) {
	int res=1;
	for(int i=1; i<=x; i++)res=(res*i)%MOD;
	return res%MOD;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	int sum=n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0)sum--;
	}
	
	cout<<jc(sum);
	return 0;
}

