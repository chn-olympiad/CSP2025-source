#include<bits/stdc++.h>
using namespace std;
 
int main(){
freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,num,e;num=0;
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>e;
		if(e>a1){
			num++;
		}
	}
	if(num%n<n and num%n!=0){
		if((num/n)%2==0){
			
			cout<<(num/n)+1<<' '<<num%n+1;
			
		}else{
			cout<<(num/n)+1<<' '<<n-num%n;
		}
	}else if(num%n==0){
		if((num/n)%2==0){
			
			cout<<(num/n)+1<<' '<<1;
		}else{
			
			cout<<(num/n)+1<<' '<<n;
		}
	}
	
	
	
	return 0;
}
