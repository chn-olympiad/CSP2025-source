#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
}	
	int c=1;
	for(int i=1;i<n*m;i++){
		if(a[0]<a[i]){
			c+=1;
		}
	}

	if(c==1){
		cout<<1<<" "<<1;
		return 0;	
	}if(c==2){
		cout<<1<<" "<<2;
		return 0;	
	}
	int s,e;
	if((c/n)%2==0){
		s=(c+(n-1))/n;
		e=c%n;
	}else{
		s=(c+(n-1))/n;
		e=n-(c%(n+1));
	}
	
	cout<<s<<" "<<e;
	
	return 0;
}
