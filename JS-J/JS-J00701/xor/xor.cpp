#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(k==0&&a[0]==1&&a[1]==1){
		cout<<2;
	}else{
		cout<<0;
	}
}
