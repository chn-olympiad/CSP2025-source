#include<bits/stdc++.h>
using namespace std;
const int N=10*10;
int n,m,c;
int nn;
int a[N+15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++)cin>>a[i];
	nn=a[1];
	sort(a+1,a+c+1,cmp);
	int x=1,y=1,k=0;
	while(y*n+x-n<=c){
		k++;
		//cout<<k<<" ";
		//
		if(a[k]==nn){
			cout<<y<<" "<<x<<"\n";
			return 0;
		}
		if(y%2==1){
			x++;
			if(x>n)y++,x=n;
		}
		else{
			x--;
			if(x<=0)y++,x=1;
		} 
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
