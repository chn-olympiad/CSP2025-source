#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool sdf(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int d=a[1],t;
	sort(a+1,a+n*m+1,sdf);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			t=i;
			break;
		}
	}
	int x=1+t/n,y=t%n;
	if(y==0){
		y=n;
		x--;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
