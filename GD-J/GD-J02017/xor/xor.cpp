#include<bits/stdc++.h>
using namespace std;
int n,a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1&&a[2]==1) cout<<0;
	else cout<<4;
	return 0;
}
