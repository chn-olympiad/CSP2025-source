#include<iostream>
#include<cmath> 
#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,k,num[260];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(n<=2){
		cout<<"0";
		return 0;
	}
	return 0;
}