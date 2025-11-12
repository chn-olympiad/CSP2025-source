#include <bits/stdc++.h>
using namespace std;
int n,m,r,a[105],x,y;
bool op;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+n*m+1);
	x=1,y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			cout<<y<<' '<<x;
			return 0;
		}
		if(!op&&x==n) y++,op=1;
		else if(op&&x==1) y++,op=0;
		else{
			if(!op) x++;
		    else x--;
		}
		
	}
	return 0; 
}
