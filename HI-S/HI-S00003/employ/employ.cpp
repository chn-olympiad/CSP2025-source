#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	cin>>n>>k;
	char c[n+5];
	int a[k+5];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>a[k];
	}
	cout<<n-k;
	return 0;
} 
