#include<bits/stdc++.h>
using namespace std;
int n,m,x,num,l,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		if (i==1){
			cin>>x;
		}
		else{
			int y;
			cin>>y;
			if (y>x)num++;
		}
	}
	num++;
	l=(num-1)/n+1;
	r=(num-1)%n+1;
	if (l%2==0){
		r=m-r+1;
	}
	cout<<l<<' '<<r;
	return 0;
} 
