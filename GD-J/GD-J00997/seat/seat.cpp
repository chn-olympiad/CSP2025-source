#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,c=0,t;
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>a){
			c++;
		}
	}
	cout<<c/n+1<<" ";
	if((c/n)%2==0){
		cout<<c%n+1;
	}else{
		cout<<n-c%n;
	}
	fclose(stdin);
	fclose(stdout);
} 
