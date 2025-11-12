#include<bits/stdc++.h>
using namespace std;
int n,m,c=1,a,b;
int main(){
	cin>>n>>m;
	int s[n*m];
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	for(int i=1;i<n*m;i++){
		if(s[0]<s[i]){
			c++;
		}
	}
	if(c%n==0){
		a=c/n;
		if(a%2==0){
			b=1;
		}else{
			b=n;
		}
		cout<<a<<' '<<b<<endl;
		return 0;
		
	}else{
		a=c/n+1;
	
	}
	if(c%n==1){
		if(a%2==0){
			b=n;
		}else{
			b=1;
		}
		cout<<a<<' '<<b<<endl;
		return 0;
		
	}
	
	if(a%2!=0){
		b=c%n;
	}else{
		b=n-c%(n+1);
	}
	cout<<a<<' '<<b<<endl;
	return 0;
}
