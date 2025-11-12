#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[112];
int ma;  //记录比R大的
int x,c,r;  //c列r行 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&x);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>x) ma++;
	}
	if(ma%m==0){
		int c=ma/m;
		if(c%2==0){
			cout<<c+1<<" "<<1;
			return 0;
		}
		else {
			cout<<c+1<<" "<<m; 
			return 0;
		}
	}
	if(ma<m){
		c=1;
		r=ma+1;
		cout<<c<<" "<<r;
		return 0;
	}
	c=ma/m; 
	r=ma%m; 
	if(c%2==0){
			cout<<c+1<<" "<<r+1;
			return 0;
	}
	else {
			cout<<c+1<<" "<<m-r; 
			return 0;
	}	
	return 0;
}