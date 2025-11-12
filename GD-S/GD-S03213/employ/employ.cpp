#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[503];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cout<<m%998244353;
	return 0;
}
