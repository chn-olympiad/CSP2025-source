#include<bits/stdc++.h>
using namespace std;
int  n,a[10086],c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	int s=n
    for(int i=1;i<=n;i++){
     	cin>>a[i];
	}
	for(int i=1;i<=n;i++){ 	
     	if(a[i]==0){
     		n--;
     		if(a[i-1]==0&&a[i+1]==0){
     			n--;
			}
		}
		if(a[i]==1){
			c++;
			if(c==n){
				cout<<s;
			}
		}
	}
	if(n!=s){
		cout<<n;
	}
	return 0;
}
