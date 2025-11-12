#include <bits/stdc++.h>
using namespace std;
int a[300];
bool cp(int a, int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+k+1,cp);
	int ret=0,x=0,y=1;
	bool flag=true;
	while(ret<=k){
		ret++;
		if(flag){
			if(x+1<=n) x++;
			else{
				y++;
				x=n;
				flag=false;
			}
		}
		else{
			if(x-1>=1) x--;
			else{
				y++;
				x=1;
				flag=true;
			}
		}
		if(a[ret]==xr){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
}
