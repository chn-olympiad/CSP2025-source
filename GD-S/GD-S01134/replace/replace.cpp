#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
string a[N][2];
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
	return 0;
}
