#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int s[105],r,x=1,y=1,z=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
		if(i==0){
			r=s[i];
		}
		else if(s[i]>r){
			if(x%2!=0){
				y++;
				if(y>n){
					y=n+1;
					x++;
				}
			}
			if(x%2==0){
				y--;
				if(y<1){
					y=1;
					x++;
				}
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}