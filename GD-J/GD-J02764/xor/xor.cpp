#include<bits/stdc++.h>
using namespace std;
int n,k,b=0,c=0,d=0,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n],e[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) b++;
		if(a[i]==0) c++;
	}
	if(b==n&&k==0){
		cout<<n;
		return 0;
	}
	if(k<=1&&b+c==n){
		if(k==1) cout<<b;
		else{
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i-1]==1){
					c++;
					a[i]=0;
				}
			}
			cout<<c;
		}
		return 0;
	} 
	return 0;
} 
