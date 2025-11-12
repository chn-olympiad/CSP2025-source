#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) num++;
		
	}	
	int c,r;
	if(num%n==0) c=num/n;
	else c=num/n+1;
	if(num%n==0){
		if(c%2==1) r=n;
		else r=1;
		
	} 
	else{
		if(c%2==1) r=num%n;
		else r=n+1-num%n;
	} 
	cout<<c<<" "<<r;
	return 0;
}
