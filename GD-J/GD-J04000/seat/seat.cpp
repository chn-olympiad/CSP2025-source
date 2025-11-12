#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m;
struct Node{
	int score;
	bool wak;
}a[1005];
int xr;
int h,s;

bool cmp(Node rr,Node rd){
	return rr.score>rd.score;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i].score;
	}
	a[1].wak = 1;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i].wak==1){
			xr = i;
			break;
		}
	}
	if(xr%n==0){
		s = xr/n;
		if(s%2==1){
			h = n;
		}
		else{
			h = 1;
		}
	}
	else{
		s = xr/n+1;
		if(s%2==1){
			h = xr-(s-1)*n;
		}
		else{
			h = n - xr + (s-1)*n + 1;
		}
	}
	cout<<s<<" "<<h;
	return 0;
}
