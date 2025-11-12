#include<bits/stdc++.h>
using namespace std;

int n,m,a[150],xh[150],yh[150]; 
int r;

bool cmp(int x,int y){
	return x>=y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	//-
	int xn=1,yn=1;
	bool f=1;
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			cout<<xn<<" "<<yn;
		}
		
		if(f){
			yn++;
			if(yn>n){
				xn++;
				yn=n;
				f=!f;
			}
		}else{
			yn--;
			if(yn<1){
				xn++;
				yn=1;
				f=!f;
			}
		}
		
	}
	
	return 0;
}
