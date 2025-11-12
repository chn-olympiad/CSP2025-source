#include<bits/stdc++.h>
using namespace std;
long long a,b[100000010],x=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		x+=b[i];
	}
	cout<<x%998244353;
	return 0; 
} 
