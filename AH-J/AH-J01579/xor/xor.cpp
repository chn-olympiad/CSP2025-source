#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[1];
return 0;
}
