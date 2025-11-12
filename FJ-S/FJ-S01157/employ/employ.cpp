#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[1001];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long sss=1;
	for(int i=n;i>=m;i--){
		sss*=i;
		sss%=998244353;
	}
	cout<<sss;
	return 0;
}
