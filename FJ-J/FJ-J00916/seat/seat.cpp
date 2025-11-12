#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m,b,c,d,e,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	b=m*n;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	c=a[0];
	sort(a,a+b);
	for(int i=b-1;i>=0;i--){
		if(a[i]==c){
			d=b-i-1;
			break;
		}
	}
	e=d/n;
	f=d%n;
	if(e%2==0){
		f=1+f;
	}
	if(e%2==1){
		f=n-f;
	}
	cout<<e+1<<" "<<f;
	return 0;
}
