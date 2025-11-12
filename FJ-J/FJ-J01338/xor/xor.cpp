#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	int n,a[1005],sum=0,m=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	} 
	for(int i=1;i<=n;i++){
		m+=a[i];
		if(a[i]>x){
			x=a[i];
		}
		if(m>2*x){
			sum++;
		}
	}
	cout<<sum%998244353;
	return 0;
} 
