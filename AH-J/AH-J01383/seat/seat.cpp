#include<bits/stdc++.h>
using namespace std;
int n,m,q=1,a,b;
int y,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n*m-1;i++){
		cin>>y;
		if(y>x) q++;
	} 
	int s=q/(n*2),s1=q%(n*2);
	if(s1<=n){
		if(s1==0){
			a=2*s;
			b=s1+1;
		}
		else{
			a=s*2+1;
		    b=s1;
		}
	}
	else{
		a=s*2+2;
		s1=s1-n;
		s1=n-s1+1;
		b=s1;
	}
	cout<<a<<" "<<b;
	return 0;
}
