#include<bits/stdc++.h>
using namespace std;
int n,m,h,l;
struct o{
	int x,i;
}a[105];
bool cmd(o x,o y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i;
	}int nn=n*m;
	sort(a+1,a+nn+1,cmd);
	int r;
	for(int i=1;i<=nn;i++){
		if(a[i].i==1){
			r=i;
			break;
		}
	}if(r%n==0) h=r/n;
	else h=r/n+1;
	l=r%n;
	if(l==0) l=m;
	if(h%2==0){
		l=m-l+1;
	}cout<<h<<" "<<l;
	return 0;
}
