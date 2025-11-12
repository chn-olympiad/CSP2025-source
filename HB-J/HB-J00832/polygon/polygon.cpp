#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			cout<<n+a[n-1];
			break;
		}
		else cout<<n+1;
		return 0;
	}
	return 0;
}
