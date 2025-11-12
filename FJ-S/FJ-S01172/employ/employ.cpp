#include<bits/stdc++.h>
using namespace std;
int n,m,a[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	cout<<n*n*s;
	return 0;
}
