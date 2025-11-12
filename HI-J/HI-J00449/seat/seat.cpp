#include <bits/stdc++.h>
using namespace std;
long long a,b,s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		scanf("%d",&b);
		if(b>a) s++;
	}
	int  c=s/n;
	if(s%n!=0) c++;
	cout<<c<<" ";
	if(c%2==0){
		if(s%n==0){
			cout<<1;
		}
		else cout<<n+1-s%n;	
	}else{
		if(s%n==0){
			cout<<n;
		}
		else cout<<s%n;		
	}	
	return 0;
} 
