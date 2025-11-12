#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[110],b,x,y,op;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,greater<long long>());
	op=1;
	x=1;
	y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			break;
		}
		if(op==1){
			y++;
			if(y==n){
				op=2;
			}
		}
		else if(op==2){
			x++;
			if(y==1){
				op=1;
			}
			else{
				op=3;
			}
		}
		else if(op==3){
			y--;
			if(y==1){
				op=2;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
