#include<bits/stdc++.h>   
using namespace std;
int n,m,d;
int a[100000];
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	if(n<=1 && m<=1){
	    cout<<	1<<" "<<1;	
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}