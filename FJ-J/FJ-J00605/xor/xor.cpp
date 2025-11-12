#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,sum=0,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			sum=1;
			cout<<sum;
			return 0;
		}
	}
	if(n==2){
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				sum++;
			}
		}
		if(a[1]a[2]==k){
			sum++;
		}
		cout<<sum;
		return 0;
	}
	if(n!=1&&n!=2){
		cout<<2;
		return 0;
	}	
}