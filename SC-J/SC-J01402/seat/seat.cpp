#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r,s,rak,x,y; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+s);
	s++;
	for(int i=1;i<s;i++){
		if(a[s-i]==r){
			rak=i;
			break;
		}
	}
	x=1+rak/n;
	y=rak%n;
	if(y==0){
		x--;
		y=n;
	}
	if(x%2==0){
		y=n+1-y;
	}
	cout<<x<<" "<<y;
	return 0;
} 