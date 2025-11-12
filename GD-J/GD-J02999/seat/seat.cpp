#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],a1,x=1,y=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(x%2==1){
			if(y<n)y++;
			else x++;
		}
		else{
			if(y>1)y--;
			else x++;
		}
		if(a[i]==a1){
			break;
		}
	}
	cout<<x<<" "<<y;
	return 0; 
} 
