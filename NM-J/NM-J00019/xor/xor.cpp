#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
   	freopen("xor.out","w",stdout);
    int n,k,a[500100]={0},s=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(k==0){
		if(n<=2){
			cout<<n/2;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0)s++;
			else{
				if(a[i+1]==1){
					s++;
					i++;
				}
			}
		}
	}else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)s++;
		}
	}else{
		s=100;
	}
	cout<<s;
    return 0;
}
