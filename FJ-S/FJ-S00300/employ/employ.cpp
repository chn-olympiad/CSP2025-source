#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,s,sum=1,c[100001];
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m;i++){
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
