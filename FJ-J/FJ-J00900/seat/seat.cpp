#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100010],z,j=0,h;
	cin>>n>>m;
	cin>>a[0];
	int c=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m);
	for(int i=m*n-1;i>=0;i--){
		if(a[i]==c){
			z=n*m-i;
			break;
		}}
	if(z%n!=0){
		h=z+n-z%n;
	}
	else{
		h=z;
	}
	if((h/n)%2==0){
		j+=1;

	}
	if(j==1){
		if(z%n==0){
			cout<<h/n<<" 1";
		}
		else{
		cout<<h/n<<" "<<n+1-z%n;}
	}
	else{
		if(z%n==0){
			cout<<h/n<<" "<<"1";
		}
		else{
		cout<<h/n<<" "<<z%n;
		}}
	return 0;}
