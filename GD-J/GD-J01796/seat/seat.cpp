#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m,x=1,y=1,big=0,flag;
	cin>>n>>m;
	int scr[n*m];
	for(int i=0;i<n*m;i++){
		cin>>scr[i];
	}
	flag=scr[0];
	for(int i=1;i<n*m;i++){
		if(scr[i]<flag) big++;
	}
	for(int i=1;i<n*m-big;i++){
		if(x%2==0){
			y--;
			if(y<1){
				x++;
				y=1;
			}
		}
		else{
			y++;
			if(y>n){
				x++;
				y=n;
			}	
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
