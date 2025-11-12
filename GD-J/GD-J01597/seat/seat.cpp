#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],s,t,n1,m1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==s){
			t=n*m-i-1;
			break;
		}
	}
	
	
	m1=t/n+1;
	if(m1%2==1){
		n1=t%n+1;
	}else{
		n1=n-t%n;
	}
	cout<<m1<<" "<<n1;
	return 0;
} 
