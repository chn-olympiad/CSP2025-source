#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[110];
	
	int n,m,f,w=0,c,r;
	cin>>n>>m;
	int nm;
	nm=n*m;
	for(int i=0;i<nm;i++){
		cin>>a[i];
	}
	f=a[0];
	sort(a,a+nm);
	for(int i=nm-1;i>=0;i--){
		w++;
		if(a[i]==f){
			break;
		}
	}
	
	c=w/n;
	if(c%2==0 && w%n !=0){
		c++;
		r=w%n;
	}else if(c%2 !=0 && w%n!=0){
		c++;
		r=n-w%n+1;
	}else if(c%2==0){
		r=1;
	}else{
		r=n;
	}
	cout<<c<<" "<<r;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
