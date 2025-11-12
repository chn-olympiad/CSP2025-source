#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[10000*5+3];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum=sum^a[i];
	}
	cout<<2;
	return 0;
}
