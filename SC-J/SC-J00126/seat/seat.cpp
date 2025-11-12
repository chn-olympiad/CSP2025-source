#include <bits/stdc++.h> 
using namespace std;
int n,m,n2,m2,x=0,y,z=1;
string a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	y=0;
	for(int i=n*m;i>0;i-=1){
		cin>>a;
		if(a[0] <= a[x]){
			y+=1;
		} 
		x+=1;		
	}
	n2=1;
	m2=1;
	for(int j=y;j>0;j-=1){
		if(z%2==1){
			if(n2<n) n2+=1;
			else if(n2==n){
				m2+=1;
				z+=1;
				if(j==0) break;
			}
		}
		if(z%2==0){
			if(n2<1) n2-=1;
			else if(n2==1){
				m2+=1;
				z+=1;
				if(j==0) break;
			}
		}
	} 
	cout <<m2<<" "<<n2;
	return 0;
} 