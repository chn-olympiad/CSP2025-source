#include<bits/stdc++.h>
using namespace std;
int c[114514];
int main(){
	freopen("employ.in","r",stdin);
	freoprn("employ.out","w",stdout);
	long long n,m,g=0;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		g+=i;
	}
	cout<<998244353ll%g;
	return 0;
}
