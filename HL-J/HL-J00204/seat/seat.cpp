#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,id,a[105] = {};
	cin>>n>>m;
	for(int i = 0;i<=n*m-1;i++)cin>>a[i];
	int f = a[0];
	sort(a,a+n*m,cmp);
	for(int i = 0;i<=n*m-1;i++){
		if(a[i]==f){
			id = i+1;
			break;
		}
	}
	int lie = id/n+1,hang = id%n;
	bool direction = lie%2;//0表示从下到上 1表示从上到下 
	if(direction == 0){
		if(hang== 0){
			x = lie-1;
			y=n;
		}
		else{
			x = lie;
			y= n-hang+1;
		}
	}
	if(direction==1){
		if(hang==0){
			x = lie-1;
			y=1;
		}
		else{
			x=lie;
			y=hang;
		}
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
