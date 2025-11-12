#include<bits/stdc++.h>
using namespace std;
int n;
long long k,sum=0;
long long a[500005]; 
bool A=true;
bool B=true;
bool C=true;
long long xr[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	xr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)A=false;
		if(a[i]>1)B=false;
		if(a[i]>225)C=false;
		xr[i]=a[i]^xr[i-1]; 
	}
	if(A){
		if(k==0)cout<<n/2;
		else if(k==1)cout<<n;
		return 0;
	}
	if(B){
		if(k==1){
			long long sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)sum++;
			}
			cout<<sum;
		}else if(k==0){
			long long sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
				if(a[i]==1&&a[i+1]==1)sum++,i++;
			} 
			cout<<sum;
		}
		return 0;
	}
	int l=1;
	for(int i=1;i<=n;i++){
		if((xr[i]^xr[l-1])==k)sum++,l=i+1;
	}
	cout<<sum;
	return 0;
}
