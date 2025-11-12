#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sel,grad;
	cin>>n>>m;
	cin>>sel;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]<sel){
			grad=i;
			break;
		}
	}
	int noww=1,nx=1,ny=1,fx=1;
	while(noww<grad){
		if(nx==1){
			if(ny%2) fx=1;
			else fx=2;
		}
		if(nx==n){
			if(ny%2) fx=2;
			else fx=3;
		}
		if(fx==1) nx++;
		else if(fx==2) ny++;
		else if(fx==3) nx--;
		noww++;
	}
	cout<<ny<<" "<<nx;
	return 0;
}