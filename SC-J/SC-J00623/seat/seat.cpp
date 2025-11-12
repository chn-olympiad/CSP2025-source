#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100+10];
int g[10+10][10+10];
int dx[4+10]={1,0,-1,0},dy[4+10]={0,1,0,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int p=0;
	int r=0;
	for(int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m; i>=1; i--){
		if(a[i]==r){
			p=n*m-i+1;
			break;
		} 
	}
	//cout<<r<<" "<<p<<endl;
	int x=0,y=0;
	int d=0;
	for(int i=1; i<=p; i++){
		if(i==1){
			x=1;
			y=1;
		}else if(i%n==0){
			x+=dx[d];
			y+=dy[d];
			d=(d+1)%4;
		}else if(i%n==1){
			x+=dx[d];
			y+=dy[d];
			d=(d+1)%4;
		}else{
			x+=dx[d];
			y+=dy[d]; 
		}
		//cout<<i<<"_"<<y<<" "<<x<<endl;
	}
	cout<<y<<" "<<x;
	return 0;
}
