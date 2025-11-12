#include<bits/stdc++.h>
using namespace std;

int main(){
	//sreopen("seat.in","r",stdin);
	//sreopen("seat.out","w",stdout);
	int n,m,q,a[100],s;
	cin>>n>>m;
	q=n*m;
	for(int i=0;i==q;i++){
		cin>>a[i];
	}for(int j=0;j<=q;j++){
		 s=max(a[j],a[j+1]);
		 
		 a[j]=s;
		 
	}if(q==1){
		cout<<1<<" "<<1;
	}


	//sclise(stdin);
	//sclise(stdout);
	return 0;
} 
