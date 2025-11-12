#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],R,X=1;
bool f=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1,x=1,y=1;i<=n*m;i++){
		if(a[i]==R){
			cout<<y<<" "<<x;
			break;
		}
		x+=X;
		if(x<1){
			x++;
			X=1;
			y++;
		}
		if(x>n){
			x--;
			X=-1;
			y++;
		}
	}
	return 0;
}
