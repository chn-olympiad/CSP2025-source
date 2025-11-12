#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,a[105],R;
bool AC(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int rp = 1;rp <= n*m;rp++) cin>>a[rp];
	R=a[1];
	sort(a+1,a+n*m+1,AC);
	int i=1,j=1,x=1;
	for(int rp = 1;rp <= n*m;rp++){
		if(a[rp]==R){
			cout<<j<<' '<<i;
			break;
		}
		if((x==-1 && i==1) || (x==1 && i==n)){
			j++;
			x=-x;
		}
		else i+=x;
	}
	return 0;
}
