#include<bits/stdc++.h>
using namespace std;
const int N=5e5+48579;
int n,k,a[N],b[N],ans,df;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)df=1; 
	}
	if(k==1&&df!=1){
		for(int i=1;i<=n;i++)
			if(a[i]==k)
				ans++; 
	}else if(k==0&&df!=1){
		for(int i=1;i<=n;i++){
			if(a[i]==k)ans++; 
		 	else if(a[i-1]==1&&a[i-1]==1&&b[i-1]==0){
					ans++;
					b[i-1]=1;
					b[i]=1;
				}	
		}
	}
	cout<<ans;
	
} 
