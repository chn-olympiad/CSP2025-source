#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[105],d,mc,ccf=1;
int mp[10][10];
int t=1;
int x=1,y=1;
bool cmpp(int xx,int yy){
	return xx>yy;
}
int main(){ 
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++){
	    cin>>a[i];	
	}
	d=a[1];
	sort(a+1,a+p+1,cmpp);
	/*for(int i=1;i<=p;i++){
	    cout<<a[i]<<' ';	
	}*/
	for(int i=1;i<=p;i++){
		if(a[i]==d){
			mc=i;
			break;
		}
	}
	if(n==1){
		cout<<1<<' '<<mc;
		return 0;
	}
	if(m==1){
		cout<<mc<<' '<<1;
		return 0;
	}
	while(true){
		if(ccf==mc){
			cout<<x<<' '<<y;
			return 0;
		}
		y+=t;
		if(y<1){
			x++;
			t=1;
			y=1;
		}
		if(y>n){
			x++;
			t=-1;
			y=n;
		}
		ccf++;	
	}
    return 0;
}
