#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k>0) cout<<a[1];
	else cout<<a[1]-1;
	return 0;	
}
