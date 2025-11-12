#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a<b){
		return b<a;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	int t=a[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
		if(a[i]>a[j]){
			swap(a[i],a[j]);
		}
		
	}
		
	}
	
		int p,e;
	for(int i=1;i<=n*m;i++){
		
		if(a[i]==t){
			int p=(i+n-1)/m;
			if(p<=0){
				p=1; 
			}
			
			cout<<p<<" ";
			if(p%2==0){
			cout<<n*p-i+1;
			
		}
		else if(p%2==1){
			cout<<i-(p-1)*n;
		}
		
			
				
			
		}
	}
	
} 
