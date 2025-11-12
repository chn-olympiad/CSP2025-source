#include<fstream>
using namespace  std;
ifstream cin("seat.in");
ofstream cout("seat.out");
int n,m,flag,book[10001]={},mc=1,aaa,x,y;
int main(){
	cin>>n>>m;
	cin>>flag;
	for(int i=2;i<=n*m;i++){
		cin>>aaa;
		book[aaa]++;
	}
	for(int i=100;i>=flag;i--){
		if(book[i]){
			mc++;
		}
	}
	x=mc/n;
	if(mc%n!=0){
		x++;
	}
	if(x%2==0){
		y=n+1-mc%n;
	}
	else{
		y=(mc-1)%n+1;
	}
	cout<<x<<" "<<y;
	cin.close();
	cout.close();
	return 0;
} 
