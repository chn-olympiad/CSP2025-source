#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001],l=1,p=1,b=1,c,d,e;
int main(){
	freopen("seat.in","r","stdin");
	freopen("seat.ans","w","stdans");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	while(p<n*m){
		if(a[1]<a[1+l]){
			b+=1;
		}
		p+=1;
		l+=1; 
	}
	c=b%n;
	d=b/n;
	e=d+1;
	if(c!=0&&e%2!=0){
		cout<<d+1<<" "<<1;
	}
	else if(c!=0&&e%2==0){
		cout<<d+1<<" "<<n;
	}
	else if(c==0&&d%2!=0){
		cout<<d<<" "<<n;
	}
	return 0;
}