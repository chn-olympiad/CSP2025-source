#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int sum=1;
int ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>x) sum++;
	}
	int p=sum/n;
	int q=sum%n;
	if(q==0){
		ansy=p;
		if(p%2==0) ansx=1;
		else ansx=n;
	}
	else{
		ansy=p+1;
		if(p%2==0) ansx=q;
		else ansx=n+1-q;
	}
	cout<<ansy<<' '<<ansx; 
	return 0;
} 
