#include<iostream>
using namespace std;
int main(int argc,char** argv){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	unsigned short n=10,m=10;
	cin>>n>>m;
	unsigned short r=100;//小R grade 
	cin>>r;
	unsigned short x=1,y=1;
	for(unsigned short i=1;i<n*m;i++){
		unsigned short temp=0;
		cin>>temp;
		if(temp>=r){
			if(x%2){
				if(y<n)y++;
				else x++;
			}else{
				if(y>1)y--;
				else x++;
			}
		}
	}
	cout<<x<<" "<<y;
}