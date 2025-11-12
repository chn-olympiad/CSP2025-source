#include<bits/stdc++.h>
using namespace std;
int c[10000];
int c2[10000];
int main(){
	freopen("seat.in","w",stdin); 
	freopen("seat.out","r",stdout);
	long long n=0,m=0;
	int x,y,z;
	cin>>n>>m;
	cin>>c[1];
	x=c[1];
	for(int i=2;i<=n*m;i++){
		cin>>c[i];
	}
	sort(c+1,c+n*m+1);
	for(int i=0;i<n*m;i++){
		c2[i+1]=c[n*m-i];
	}
	for(int i=1;i<=n*m;i++){
		if(c2[i]==x){
	    y=i;
		}	
	}	
	int a=y%n;
	if(a==0){
		z=y/n;
	}else{
		z=(y-a)/n+1;
	}
	if(a==0){
	if(z%2==0){
		cout<<z<<" 1";
		return 0;
	}else{
		cout<<z<<" "<<n;
		return 0;
	}
	}
	if(z%2!=0){
		cout<<z<<" "<<a;
	}else{
		cout<<z<<" "<<n-a+1;
	}
//666sort cmp£¬forget£¬Can you help me	
	return 0;
}	
