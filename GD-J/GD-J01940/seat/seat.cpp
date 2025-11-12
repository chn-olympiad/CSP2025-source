#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ud=0;
	int x=1,y=1;
	int n,m,number=1,xm,temp;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		if(i==1){
			cin>>xm;
		}
		else{
			cin>>temp;
			if(temp>xm){
				number++;
			}
		}
	}
	if(number==1){
		cout<<"1 1";
	}
	else{
		for(int i=2;i<=n*m;i++){
			if(y==n){
				ud--;
			}
			if(y==1){
				ud++;
			}
			if(ud!=0){
				y+=ud;
			}
			else{
				x++;
			}
			if(i==number){
				cout<<x<<" "<<y;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
