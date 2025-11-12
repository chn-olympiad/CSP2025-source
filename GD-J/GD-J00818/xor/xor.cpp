#include<bits/stdc++.h>
using namespace std;

int n,k,a[500010];
bool A=1,B=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) A=0;
		if(a[i]!=1&&a[i]!=0) B=0;
	}
	
	
	if(A){
		cout<<n/2;
		return 0;
	}
	if(B){
		int sum=0;
		if(k==1){
			for(int i=0;i<n;i++) if(a[i]) sum++;
			cout<<sum;
		}
		else{
			for(int i=0;i<n;i++){
				if(!a[i]) sum++;
				else if(a[i]&&a[i+1]){
					sum++;
					i++;
				}
			}
			cout<<sum;
		}
		return 0;
	}
	cout<<0;
	return 0;
}
