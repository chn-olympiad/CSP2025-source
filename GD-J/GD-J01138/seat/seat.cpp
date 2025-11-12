#include <iostream>
using namespace std;

int n,m;
int seat[107];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	int s=n*m,x,r1,cnt=1,ansx,ansy;
	cin>>r1;
	for(int i=2;i<=s;i++){
		cin>>x;
		if(x>r1){
			cnt++;
		}
	}
	if(cnt%m==0){
		ansx=cnt/m;
	}else{
		ansx=cnt/m+1;
	}
	if(ansx%2==1){
		ansy=cnt-(ansx-1)*m;
	}else{
		ansy=m-(cnt-(ansx-1)*m)+1;
	}
	cout<<ansx<<' '<<ansy;
	return 0;
} 
