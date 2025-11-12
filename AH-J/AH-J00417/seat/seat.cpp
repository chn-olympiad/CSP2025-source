#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],b[20][20],p,q;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			q=i;
			break;
		}
	}
	int c,r,f=1;
	c=q/n;
	if(q%n>0){
		c++;
		f=0;
	}
	if(c%2==1){
		if(f==1){
			r=n;
		}else{
			r=q-(c-1)*n;
		}
	}else{
		if(f==1){
			r=1;
		}else{
			r=n-(q-(c-1)*n)+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
