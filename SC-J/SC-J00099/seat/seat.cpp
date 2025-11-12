#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m,q=1,x,y;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){		
		cin>>a[i];
		if(a[i]>a[1])
			q++;
	}
	x=q%n;
	y=q/n;
	if(x==0){
		if(y%2==0)
			cout<<y<<" "<<1;
		else
			cout<<y<<" "<<n;
	}
	else{
		y++;
		if(y%2==0)
			cout<<y<<" "<<n-x+1;
		else
			cout<<y<<" "<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 