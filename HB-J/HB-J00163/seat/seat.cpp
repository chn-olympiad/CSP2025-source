#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b,c,d=1;
	int x,y;
	b=n*m;
	int a[b];
	cin>>c;
	a[1]=c;
	for(int i=2;i<=b;i++){
		cin>>a[i];
	}
	for(int i=1;i<=b;i++){
		if(a[i]>c){
			d=d+1;
		}
	}
	x=d%n;
	y=d/n;
	if(d%n!=0){
		
		y++;
	if(x%n==0)x=n;
	}
	if(y%2==0){
		x=n-x+1;
	}
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
