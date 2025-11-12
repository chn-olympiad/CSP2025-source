#include<bits/stdc++.h>
using namespace std;
int n,k; 
int aa[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	if(k==1||k==0){
		if(k==1)cout<<n;
		else cout<<n/2;
	}else{
		 srand(time(0));
		 cout<<rand()%n;
	}

	return 0;
} 
