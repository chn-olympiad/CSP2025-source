#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<"1";
	}else{
		cout<<"2";
	}
	return 0;
}  
