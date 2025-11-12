#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a=1,x,temp,c,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x;
		if(i==1)
		temp=x;
		else if(x>temp)
		a++;
	}
	c=a/n;
	y=a%n;
	if(y==0){
		cout<<c<<" "<<n;
	}
	else if(c%2==0)
	cout<<c+1<<" "<<y;
	else
	cout<<c+1<<" "<<n-y+1;
	return 0;
}