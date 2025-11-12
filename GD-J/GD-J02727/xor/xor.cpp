#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
int sum1,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
		if(a[i]==0){
			sum1++;
		}
	}
	if(k==0){
		cout<<sum1;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[j]-s[i]==k){
					sum++;
					i=j;
				}
			}
		}
	}
	cout<<sum;
	return 0;
//<二二二二> 
