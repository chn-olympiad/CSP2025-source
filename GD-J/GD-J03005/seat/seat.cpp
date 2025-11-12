#include<bits/stdc++.h>
#define TIMU (string)"seat"
using namespace std;
int a[12345],xr = -1;
int main(){
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);//ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
	}
	xr = a[0];
	sort(a,a+n*m,[&](int a,int b){
		return a>b;
	});
	/*for(int i = 0;i<n*m;i++){
		cout<<a[i]<<endl;
	}*/
	int nx=0,ny=0,md=0;
	int a_x,a_y;
	for(int i = 0;i<n*m;i++){
		//printf("nx=%d ny=%d md=%d i=%d[cj=%d]\n",nx,ny,md,i,a[i]);
		if(a[i]==xr){
			a_x = nx+1;
			a_y = ny+1;
			printf("%d %d\n",a_y,a_x);// y x
		}
		if(nx<n-1 && md==0) nx++;
		else if(nx>0 && md==1) nx--;
		else if(nx==n-1 && md==0){
			md = 1;
			ny++;
		}
		else if(nx==0 && md==1){
			md = 0;
			ny++;
		}
	}
	return 0;
}
/*
2 2
98
99
100
97
*/
/*
3 3
94 95 96 97 98 99 100 93 92
*/
