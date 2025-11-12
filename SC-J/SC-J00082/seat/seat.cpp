#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int r;

bool ak(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	sort(a+1,a+n*m+1,ak);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
//	cout<<r<<' ';
	int x=1,y=1;
	for(int i=1;i<r;i++){
		if(x%2==1){
			y++;
			if(y>n){
				x++;
				y--;
			}	
		}
		else{
			y--;
			if(y<1){
				x++;
				y++;
			}
		} 
	}
	cout<<x<<' '<<y;
	return 0;
}