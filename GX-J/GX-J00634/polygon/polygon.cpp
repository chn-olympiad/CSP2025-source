#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a;cin>>n;
	int c[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a;
		c[i]=a+c[i-1];
	}
	cout<<c[n-1];
	return 0;
}
