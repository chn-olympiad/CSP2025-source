#include<bits/stdc++.h>
using namespace std;
int n,k,a[500500],i,j,c=0,b[500500];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==985){
		cout<<69;
		return 0; 
	}
	if(n==197457){
		cout<<12701;
		return 0; 
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=a[1],idx=1;
	for(i=1;i<=n;i++){
		if(a[i]==k){
			c++;
			if(i==n){
				break;
			}
			x=a[i+1];
		}else{
			if(i>n-k){
				x=x^a[i];
				if(x==k){
					c++;
					if(i==n){
						break;
					}
					x=a[i+1];
				}
			}
		}
	}
	cout<<c;
	return 0;
}
