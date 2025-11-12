#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b[101],c,num,seat_n,seat_m,p;
int main(){
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++)
		cin>>b[i];
	num=b[1];
	sort(b+1,b+c+1);
	for(int i=1;i<=c;i++)
		if(num==b[i]){
			p=i;
			break;}
	seat_n=p/n+1;
	seat_m=p%n;
	if(seat_n%2==0)
		seat_m=n-seat_m;
	cout<<seat_m<<' '<<seat_n;
}
