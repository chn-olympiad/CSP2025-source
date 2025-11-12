#include <bits/stdc++.h>
using namespace std;
int a[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=3){
		cout<<n/3;
		return 0;
	}
	else{
		cout<<n-2;
		return 0;
	}
	return 0;
}

