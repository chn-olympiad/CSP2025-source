#include<bits/stdc++.h>
using namespace std;
int n,m,len=0,x=0,y=0;
struct node{
	int scor;
	bool f=false;
}a[10005];
bool cmp(node x,node y){
	return x.scor>y.scor;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i].scor;
	}
	a[1].f=true;
	int b=n*2;
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(a[i].f){
			x=i%b;
			if(x==0) x=1; 
			if(x>n){
				x-=n;
				x=n-x+1;
			}
			y=(i-1)/n+1;
		}
	}
	cout<<y<<' '<<x;
	return 0; 
}
