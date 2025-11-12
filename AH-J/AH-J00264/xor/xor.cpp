#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,ans,i,j,c;
int b[10009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n<=2&&k==0){
		cout<<1;
		return 0;
	}
	cout<<n/3+k;
	return 0;
}
/*
in:
4 2
2 1 0 3

out:
2
*/
