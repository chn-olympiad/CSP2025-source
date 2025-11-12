#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,x,y,len=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)len++;
	}
	int tmp=len%n;
	if(tmp==0)x=len/n;
	else x=len/n+1;
	if(x%2==1){
		if(tmp==0)y=n;
		else y=tmp;
	}
	else {
		if(tmp==0)y=1;
		else y=n-tmp+1;
	}
	cout<<x<<" "<<y;
	return 0;
} 
