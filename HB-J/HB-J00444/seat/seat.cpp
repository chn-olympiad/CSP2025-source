#include <iostream>
#include <cstdio>
using namespace std;
int n,m,s=1,l,x5=1,y=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>l;
	for(int i=2,x;i<=n*m;i++){
		cin>>x;
		if(x>l){
		//	cout<<111;
			if(y%2==1){
				if(x5==1)y++;
				else x5--;
			}
			else {
				if(x5==n)y++;
				else x5++;
			}
		}
	}
	cout<<y+1<<' '<<x5;
	return 0;
}
