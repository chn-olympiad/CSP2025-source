#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,s,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	for(int j=1;j<=n*m;j++){
		if(s==a[j])r=j;
	}
	int d=n*m-r+1; 
	if(d<=n){
		cout<<1<<" "<<d;
	}
	else{
		int x,y;
		x=d/n;
		y=d%n;
		if(y==0){
			if(x%2==0)cout<<x<<" "<<1;
			else cout<<x<<" "<<n;
		}
		else
		{
			x=x+1;
			if(x%2==0)cout<<x<<" "<<n-y+1;
			else cout<<x<<" "<<y;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
