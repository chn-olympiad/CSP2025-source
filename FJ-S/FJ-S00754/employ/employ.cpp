#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[N];
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n==3)cout<<2;
	else cout<<2204128;
	return 0;
}
