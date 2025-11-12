#include<bits/stdc++.h>
using namespace std;
int aknoi[10002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a0=0,a1=1;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>aknoi[i];
		if(aknoi[i]==0) a0++;
		else a1++;
	}
	if(k==0){
		cout<<(a0*(a0-1))/2+(a1*(a1-1))/2+a0;
	}else{
		cout<<a0*a1+a1;
	}
	return 0;
} 
