#include<bits/stdc++.h>
using namespace std;
//x代表在x列 y代表在y行 
int n,m,x,y,s,a[500005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[1]) s++;
	}
	s+=1;
	x=1;
	y=1;
	for(int i=2;i<=s;i++){
		if(x%2==1) y++;
		else y--;
		if(y==n+1){
			y=n;
			x++;
		}
		if(y==0){
			y=1;
			x++;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 
