#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000010],A=1,B=1,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0){
		A=0;
		if(k!=1){
			B=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			A=0;
			if(a[i]!=0){
				B=0;
			}
		}
	}
	if(A==1){
		cout<<n/2;
	}else if(B==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					s++;
				}else if(a[i+1]==1){
					s++;
					i++;
				}
			}
			cout<<s;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					s++;
				}
			}
			cout<<s;
		}
	}
	return 0;
}
