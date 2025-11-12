#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=2) {
		cout<<0;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int Max=max(a,max(b,c));
		if(a+b+c>Max*2) cout<<1;
		else cout<<0;
	}
}