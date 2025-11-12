#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,a,x=1,y=1;
	cin>>n>>m>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>r){
			y++;
			if(y>n){
				y=1;
				x++;
			}
		}
	}
	if(x%2==0) y=n+1-y;
	cout<<x<<' '<<y;
	return 0;
}