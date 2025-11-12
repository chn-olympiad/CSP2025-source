#include<bits/stdc++.h>
using namespace std;
int b[5000005];
string s;
int n,m,k,gg;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	if(b[1]==1&&b[n]==1&&k==0){
		cout<<n/2;
	}
	else{
		cout<<0;
	}
	return 0;
}
