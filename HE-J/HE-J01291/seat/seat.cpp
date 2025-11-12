#include<bits/stdc++.h>
using namespace std;
int main(){
	//feropen("seat.in","r",stdin);
	//feropen("seat.out","w",stdout);
	int n,m,c,x=1,y=1;
	cin>>n>>m>>c;
	int sum=n*m-1;
	while(sum--){
		int x1;
		cin>>x1;
		if(x1>c){
			if(x==1){
				if(y%2==0)y++;
				else x++;
				continue;
			}
			if(x<n){
				if(y%2)x++;
				else x--;
				continue;
			}
			if(x==n){
				if(y%2)y++;
				else x--;
				continue;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
