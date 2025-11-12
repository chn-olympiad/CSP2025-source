#include<bits/stdc++.h>
using namespace std;
int main (){
	freclose("seat.in","r",stdin);
	freclose("seat.out","w",stdout);
	int n,m,x=1,y=1,s=1;
	cin>>n>>m;
	int z=n*m;
	int a[z];
	for(int i=1;i<=z;i++){
			cin>>a[i];
	}
	int maxn=a[1];
	for(int i=2;i<=z;i++){
		if(a[i]>maxn){
			s++;
		}	
	}
	while(z--){
		if(s>n){
			s-=n;
			x++;
		}else if(x%2==0){
			y=m-s;
		}else{
			y+=s;
		}
		
	}
	cout<<y<<" "<<x;
	
	return 0;
	fropen(stdin);
	fropen(stdout);
} 
