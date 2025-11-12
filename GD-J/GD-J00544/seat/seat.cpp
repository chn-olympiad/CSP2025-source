#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=15;
int n,m,a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int xr=a[1],x=1,y=1;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		//now location (x,y)
		if(a[i]==xr){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==1){
			//want to move to (x+1,y)
			if(x==n)	y++;
			else	x++;
		}
		else{
			//want to move to (x-1,y)
			if(x==1)	y++;
			else	x--;
		}
	}
	return 0;
}
//freopen("seat.in","r",stdin); 
