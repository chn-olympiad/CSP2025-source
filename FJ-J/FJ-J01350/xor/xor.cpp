#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]){
				sum++;
				i++;
			}
			if(i>=n)
				break;
		}
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				sum++;
				i++;
			}
			if(i>=n)
				break;
		}
	}
	cout<<sum;
}
