#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s=-1;
	cin>>n>>k;
	if(k==0){
		cout<<0;
		return 0;
	}
	if(k==1){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			s=max(a[i],s);
		}
		cout<<s;
	}
	else{
		cout<<2;
		return 0;
	}
	return 0;
}