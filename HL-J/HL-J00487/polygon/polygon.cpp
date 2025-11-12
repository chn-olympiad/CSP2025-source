#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<2n-1;
	return 0;
}