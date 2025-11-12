#include<bits/stdc++.h>
using namespace std;
int c,r,n,a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>r>>c;
	n=r*c;
	int rank=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[1])rank++;
	}
	int x,y;
	x=rank/r;
	if(rank%r!=0)x++;
	if(x&1){
		if(rank%r==0)y=r;
		else y=rank%r;
	}
	else{
		if(rank%r==0)y=1;
		else y=r-rank%r+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
