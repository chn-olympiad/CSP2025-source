#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050],sum=0,flag[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
		}else if(a[i]==a[i+1]){
			if(k==0){
				sum++;
				i++;
			}
		}else{
			if(k==1){
				sum++;
				i++;
			}
		}
	}
	cout<<sum;
}
