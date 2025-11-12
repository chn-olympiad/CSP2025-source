#include<bits/stdc++.h>
using namespace std;
int a;
int b[109];
int n,m;
int ax;
int x,y;
int main(){
    freopen(seat.in,'r',stdin);
	freopen(seat.out,'w',stdout);
	cin >> n >> m;
	int u=0;
	for(int i=1;i<=n*m;i++){
		cin >> u;
		if(i==1){
			a=u;
		}
		b[u]++;
    }
    for(int i=100;i>=0;i--){
		if(b[i]>0){
			ax++;
		}
		if(i==a){
			break;
		}
	}
	if(ax%n==0){
		y=n;
	}else{
		y=ax%n;
	}
	x=ax/n;
	cout<<x<<" "<<y<<endl;
	return 0;
}
