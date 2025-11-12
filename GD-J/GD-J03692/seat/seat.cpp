#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int s=0;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	int pm=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]<=s){
			pm++;
		}
	}
	pm=n*m-pm+1;
	int x,y;
	if(pm<=n){
		x=1;
		y=pm;
	}
	else{
		if(pm%n==0){
			x=pm/n;
		}
		else {
			x=pm/n+1;
		}
		if(x%2==0){
			y=pm-(x-1)*n-(n-1);
			if(y==0) y=m;
		}
		else{
			y=pm-(x-1)*n;
		}
	}
	cout << x << " " << y;
	return 0;
}
