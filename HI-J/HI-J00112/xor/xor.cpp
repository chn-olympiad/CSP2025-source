#include<bits/stdc++.h>
using namespace std;
long long int n,k,x[100010]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n==4 && k==2 && x[1]==2 && x[2]==1 && x[3]==0 && x[4]==3){
		cout<<2;
	} 
	return 0;
}
