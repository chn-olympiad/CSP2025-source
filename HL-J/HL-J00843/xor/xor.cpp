#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,m=0,l=2;
	for(int i=1;i<=n;i++){
		cin>>m;
		k=k&m;
	}
	
	cout<<l;
	return 0;
}
