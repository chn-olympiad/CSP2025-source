#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b;
	cin>>n>>m;
	cin>>a;
	int s=1;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)s++;
	}
	int x=s/n,y=s%n;
	if(y>0)x++;
	if(y==0)y=m;
	if(x%2==0){
		y=m-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
