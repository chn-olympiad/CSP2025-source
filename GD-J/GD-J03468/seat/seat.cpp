#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,q,c;
	scanf("%d %d",&n,&m);
	int a;
	cin>>a; 
	int r=a,b=1;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>r) b++;
	}
	q=(b-1)/n+1,c=(b-1)%n+1;
	if(q%2!=0){
		p=c;
	}
	else{
		p=n-c+1;
	}
	cout<<q<<" "<<p;
	return 0;
}
