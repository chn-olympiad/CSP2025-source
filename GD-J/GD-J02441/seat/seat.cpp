#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	int u,v;
	u=floor(y/1.0/n+0.9);
	v=y%n;
	if(v==0){
		v=n;
	}
	if(u%2==0){
		v=n-v+1;
	}
	cout<<u<<' '<<v;
	return 0;
}
