#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[105],b,c=1;
	cin>>n>>m;
	int g=n*m;
	for(int i=1;i<=g;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+g);
	for(int i=g;i>=1;i--){
		
		if(a[i]==b){
			b=c;
			
		}
			c++;
			
		}
	
	cout<<b;
	cout<<(b/n)+1<<" ";
	if(b%m==0){
		cout<<m;	
	}else{
		cout<<b%m;
	}
}
