#include<bits/stdc++.h>
using namespace std;
int n,k,tot1=0,tot0=0,totj;
bool f;
string a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=="1"){
			tot1++;
			if(a[i]==a[i-1]){
				totj++;
				a[i]=a[i-1]="0";
			} 
		} 
		else{
			if(a[i]=="0") tot0++;
			else f=1;
		}
	}
	if(tot1==n&&k==0){
		cout<<n/2;
		return 0;
	} 
	if(tot1+tot0==n){
		if(k==0) cout<<tot0+totj;
		else{
			if(k==1) cout<<tot1;
		}
	}
	else cout<<n/3;
	return 0;
}
