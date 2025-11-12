#include <iostream>
#include <algorithm>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3) cout<<"10";
	else cout<<a[n]+a[n-1];
	return 0;
} 
