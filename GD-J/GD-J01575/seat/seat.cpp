#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rpoint,c,rand;
	cin>>n>>m;
	int point[n*m]={0};
	cin>>rpoint;
	point[0]=rpoint;
	for(int i=1;i<n*m;i++){
		cin>>point[i];
	}
	sort(point,point+n*m);
	for(int i=0;i<n*m;i++){
		if(point[i]==rpoint){
			rand=n*m-i-1;
			break;
		}
	}
	c=rand/m+1;
	cout<<c<<' ';
	if(c%2){
		cout<<rand%m+1;
	}else{
		cout<<n-rand%m;
	}
	return 0;
}
