#include<bits/stdc++.h>
using namespace std;
int n,m,mf,mp=0;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m>>mf;
	for(int i = 1; i < n*m; i++){
		int x;
		cin>>x;
		if(x>mf)mp++;
	}
	int y=mp%n,x=mp/n+1;
	if(x%2){
		cout<<x<<" "<<y+1<<endl;
	}
	else{
		cout<<x<<" "<<n-y<<endl;
	}
	
	
	return 0;
}
