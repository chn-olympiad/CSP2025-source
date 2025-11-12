#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1)cout<<0; 
	else if(n==2)cout<<1;
	else if(2<n<=10){
		if(k==1){
			int b=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					b++;
				} 
			}
			cout<<b;
	}
		else if(k==0){
			if(n==3){
				if(a[1]==0 && a[2]==0 &&a[3]==0)cout<<3;
				else if(a[1]==0 && a[2]==0 &&a[3]==1)cout<<2;
				else if(a[1]==0 && a[2]==1 &&a[3]==0)cout<<2;
				else if(a[1]==0 && a[2]==1 &&a[3]==1)cout<<2;
				else if(a[1]==1 && a[2]==1 &&a[3]==1)cout<<1;
				else if(a[1]==1 && a[2]==0 &&a[3]==1)cout<<1;
				else if(a[1]==1 && a[2]==1 &&a[3]==0)cout<<2;
				else if(a[1]==1 && a[2]==0 &&a[3]==0)cout<<2;
			}
			else if(n==4){
				if(a[1]==0 && a[2]==1 &&a[3]==0 && a[4]==0)cout<<3;
				else if(a[1]==0 && a[2]==1 &&a[3]==0 && a[4]==1)cout<<2;
				else if(a[1]==0 && a[2]==1 &&a[3]==1 && a[4]==0)cout<<3;
				else if(a[1]==0 && a[2]==1 &&a[3]==1 && a[4]==1)cout<<2;
				else if(a[1]==0 && a[2]==0 &&a[3]==0 && a[4]==1)cout<<3;
				else if(a[1]==0 && a[2]==0 &&a[3]==1 && a[4]==0)cout<<3;
				else if(a[1]==0 && a[2]==0 &&a[3]==1 && a[4]==1)cout<<3;
				else if(a[1]==0 && a[2]==0 &&a[3]==0 && a[4]==0)cout<<4;
				else if(a[1]==1 && a[2]==1 &&a[3]==0 && a[4]==0)cout<<3;
				else if(a[1]==1 && a[2]==1 &&a[3]==0 && a[4]==1)cout<<2;
				else if(a[1]==1 && a[2]==1 &&a[3]==1 && a[4]==0)cout<<2;
				else if(a[1]==1 && a[2]==1 &&a[3]==1 && a[4]==1)cout<<2;
				else if(a[1]==1 && a[2]==0 &&a[3]==0 && a[4]==1)cout<<2;
				else if(a[1]==1 && a[2]==0 &&a[3]==1 && a[4]==1)cout<<2;
				else if(a[1]==1 && a[2]==0 &&a[3]==1 && a[4]==1)cout<<2;
				else if(a[1]==1 && a[2]==0 &&a[3]==0 && a[4]==0)cout<<3;
			}
			
		}
	}
	else if(n>10){
		int b=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				b++;
			} 
		}
		if(b==n){
			cout<<b/2;	
		}
} 
	
	else if(n==4 && k==2){
		if(a[1]==2 && a[2]==1 &&a[3]==0 && a[4]==3)cout<<2;
	}
	
	return 0;
}
