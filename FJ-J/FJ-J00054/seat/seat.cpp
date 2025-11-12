#include<bits/stdc++.h>
using namespace std;
int i,a[200],m,n,c,d,e,f;
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	c=a[1];
	for(i=2;i<=m*n;i++){
		cin>>a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	for(i=1;i<=m*n;i++){
		if(a[i]==c){
			d=i;
			break;
		}
	}
	if(d%n==0){
		e=d/n;
		if(e%2==0)
			f=n;
		else
			f=1;
	}
	else{
		e=d/n+1;
		if(e%2==1)
			f=d-d/n*n;
		else
			f=n-(d-d/n*n)+1;
	}
	cout<<e<<" "<<f<<endl;
	return 0;
} 
