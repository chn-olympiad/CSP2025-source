#include <bits/stdc++.h>
using namespace std;
int x,y,n,m,s;
int c,r;
struct node{
	int fs,mc;
}a[110];
bool cmp(node x,node y){
	return x.fs >y.fs ;
}

int main(){
	freopen("seat2.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int R;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
	}
	R=a[1].fs ;
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=m*n;i++){
		if(a[i].fs==R ){
			s=i;
			break;
		}
	}
	if(s<=n){
		cout<<1<<' '<<s;
		return 0;
	}
	y=2;
	for(int j=n;j<=n*m;j++){
		if(s<=y*n){
			if(y%2==1){
				r=y*n-s;
				c=y;
			}
			else{
				r=y*n-s+1;
				c=y;
			}	
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
