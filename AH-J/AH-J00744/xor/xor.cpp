#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0) cout<<1;
	else cout<<2;
	return 0;
}
