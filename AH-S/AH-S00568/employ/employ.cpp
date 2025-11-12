#include "bits/stdc++.h"
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>m>>n;
	m=1;
	for(int i=1;i<=n;i++){
		m*=i;
		m%=998244353;
	}
	cout<<m<<endl;
	return 0;
}
