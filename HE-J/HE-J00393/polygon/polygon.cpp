#include <bits/stdc++.h>
using namespace std;
int a[1005],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=3){
		cout<<a[2]+a[3]+a[4];
	}
	return 0;
}
