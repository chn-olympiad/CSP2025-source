#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],s;
bool b,b2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=1;
		}
		if(a[i]!=1&&a[i]!=0){
			b2=1;
		}
	}
	if(n==1){
		cout<<(a[0]==k);
		return 0;
	}
	if(n==2){
		cout<<max(a[0] xor a[1]==k,(a[0]==k)+(a[1]==k));
		return 0;
	}
	if(!b){
		cout<<n/2;
		return 0;
	}
	if(!b2){
		if(k==0){
			for(int i=0;i<n-1;i++){
				if(a[i]){
					if(a[i+1]){
						a[i+1]=0;
					}
				}
				else{
					s++;
				}
			}
			if(a[n-1]==0){
				s++;
			}
		}
		else{
			for(int i=0;i<n-1;i++){
				if(a[i]!=a[i+1]){
					s++;
					i++;
				}
			}
		}
		cout<<s;
		return 0;
	}
	return 0;
} 
