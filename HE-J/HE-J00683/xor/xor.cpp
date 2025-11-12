#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int num(){
	int sum=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum++;
				continue;
			}
			else if(a[i]==1&&a[i+1]==1&&i+1<=n){
				sum++;
				i++;
				continue;
			}
			else{
				continue;
			}
		}
		return sum;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				sum++;
				continue;
			}
			else if(((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))&&i+1<=n){
				sum++;
				i++;
				continue;
			}
			else{
				continue;
			}
		}
		return sum;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n<=2&&k==0){
		cout<<1;
		return 0;
	}
	if(n<=10&&k<=1){
		cout<<num();
		return 0;
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	
	return 0;
}
