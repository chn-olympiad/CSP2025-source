#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000],cj;
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	cj=a[1];
	int x,y;
	x=cnt/n+1;
	y=cnt%n+1;
	if(x%2==0)
		y=m-y+1;
	cout<<x<<" "<<y;
	return 0;
} 