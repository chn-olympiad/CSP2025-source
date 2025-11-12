#include<bits/stdc++.h>
using namespace std;
long long n,m,a,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	long long r=n*m,sum=1;
	for(int i=1;i<r;i++){
		cin>>a;
		if(a>x)sum++;
	}
	
	long long x=sum%n,y=sum/n+(sum%n!=0);
	if(x==0)x=n;
	
	if(y%2==0){
		cout<<y<<' '<<n-x+1; 
	} 
	else cout<<y<<' '<<x;
	return 0;
}