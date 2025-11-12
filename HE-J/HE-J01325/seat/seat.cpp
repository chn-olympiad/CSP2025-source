#include<bits/stdc++.h>
using namespace std;
int n,m,x[10001],z;
int main(){
//	feropen("number.in","w",stdin);
//	feropen("number.out","r",stdout);
	cin>>n>>m;
	z=1;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n*m;i++){
		if(x[1]<x[i]) z++;
	}
	if(z%n!=0&&z%n==1&&n!=2){
		cout<<z/n+1<<" "<<"1";
	}else if(z%n!=0){
		cout<<z/n+1<<" "<<z-1;
	}else{
		if((z/n)%2==0) cout<<z/n<<" "<<"1";
		else cout<<z/n<<" "<<n;
	}
	return 0;
}
