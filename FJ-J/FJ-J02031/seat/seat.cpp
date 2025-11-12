#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,atwo,x=1,y=1;
	cin>>a;
	int b=1;
	for(int i=2;i<=n*m;i++){
		cin>>atwo;
		if(atwo>a){
			y+=b;
		}
		if(y>n||y<1){
			x++;
			y-=b;
			b=-b;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}

