#include<bits/stdc++.h>
using namespace std;
int n,m,nm[200],ai=0,pr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>nm[i];
		if(i==0) ai=nm[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(nm[j]>nm[i]) swap(nm[j],nm[i]);
		}
	}
	for(int i=n*m-1;i>=0;i--) if(ai==nm[i]) pr=n*m-i; 
	if(pr%n==0) {
		cout<<pr/n<<" ";
		if(pr/n%2==0) cout<<1;
		else cout<<n;
	} 
	else{
		if(pr<=n) cout<<1<<" "<<pr;	
		else{
			cout<<pr/n+1<<" ";
			if((pr/n+1)%2==0) cout<<(pr%n)*2;
			else cout<<pr%n;
		}
	}
	
	
	
	
	return 0;
} 
