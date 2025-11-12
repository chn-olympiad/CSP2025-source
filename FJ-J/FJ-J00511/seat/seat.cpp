#include <bits/stdc++.h>
using namespace std;

int n,m;
int a,order=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for (int i=1,t;i<n*m;i++){
		cin>>t;
		if (t>a) order++;
	}
	
	int col=ceil(1.0*order/n),row=order%m;
	if (col%2==1){
		if (row==0) row=m;
	}else{
		if (row==0) row=1;
		else row=m-row+1;
	}
	
	cout<<col<<' '<<row;
	
	
	
	return 0;
}
