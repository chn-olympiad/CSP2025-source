#include<iostream>
#include<cmath>
#include<algorithm>
int a[105],n,m,k,h,sum=1,x=1,y=1;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m>>h;
	for(int i=2;i<=n*m;i++){
		cin>>k;
		a[k]++;
	}
	for(int i=100;i>h;i--){
		if(a[i]){
			if((y==1&&x%2==0)||(x%2==1&&y==n)) x++;
			else if(x%2==1) y++;
			else y--;
			
		}
	}
	cout<<x<<" "<<y;
	return 0;
}