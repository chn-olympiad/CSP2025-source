#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,shu=0,a;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=k){
			shu++;
		}
	}
	cout<<shu;
	return 0;
} 
