#include <bits/stdc++.h>
using namespace std;

int a[10];
int sum,n;
int main(){
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
		sum += a[i];
	}
	sort(a+1,a+n+1);
	//cout<<sum<<' '<<a[n]<<endl;
	if (sum <= a[n]*2 || n < 3) cout<<0<<endl;
	else cout<<1<<endl;
	return 0;
}
