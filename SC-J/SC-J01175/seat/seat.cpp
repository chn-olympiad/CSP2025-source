#include<bits/stdc++.h>
using namespace std;
int m,n,a,b,c=1,d,e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<m*n;i++){
		cin>>b;
		if(a<b) c++;
	}
	if(c%n!=0) d=c/n+1;
	else d=c/n;
	if(d%2!=0) e=c-(d-1)*n;
	else e=n+(d-1)*n-c+1;
	cout<<d<<' '<<e;
	return 0;
}