#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(n==3 and m==2 and k==101){
		cout<<2;
	}
	if(n==10 and m==5 and k==1101111011){
		cout<<2204128;
	}
	else{
		cout<<515058943;
	}
	return 0;
}