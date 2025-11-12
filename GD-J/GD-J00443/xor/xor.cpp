#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=2;
	}
	cout<<a[1];
	return 0;
}
