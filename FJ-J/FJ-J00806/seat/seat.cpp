#include<bits/stdc++.h>
using namespace std;

int a[10005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cj;
	cin>>cj;
	a[1]=cj;
	int wz=1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>cj){
			wz++;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int ds,ys;
	ds=ceil(wz*1.0/n);
	ys=wz%n;
	int x=ds,y;
	if(ds%2==1){
		if(ys!=0){
			y=ys;
		}
		else{
			y=n;
		}
	}
	else{
		if(ys!=0){
			y=n-ys+1;
		}
		else{
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
