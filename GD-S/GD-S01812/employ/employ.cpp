#include<iostream>
using namespace std;
long long a,b,c=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	for(int i=a;i>a-b;i--){
		c*=i;
	}
	cout<<c%998244353;
	return 0;
}
