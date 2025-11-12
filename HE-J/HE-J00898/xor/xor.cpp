#include<bits/stdc++.h>
using namespace std;
long long a,b,c[10000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	cout<<c[1];
	return 0; 
} 
