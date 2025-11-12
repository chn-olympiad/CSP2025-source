#include <iostream>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1,h;
	cin>>n>>m;
	cin>>h;
	for(int i=1;i<=n*m-1;i++){
		int a;
		cin>>a;
		if(a>h)
		cnt++;
	}
	int x,y;
	if(cnt%n==0){
		x=cnt/n;
		y=n;
	}
	else
    {x=cnt/n+1;
    y=cnt%n;}
    cout<<x<<" ";
	 if(x%2==0){
	 	cout<<n-y+1;
	 }
	 else
	 cout<<y;
	return 0;
}
