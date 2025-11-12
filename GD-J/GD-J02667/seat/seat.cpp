#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R;
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
	R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=0,y=0,z=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			x=i;break;
		}
	}
	y=x/n;z=x%n;
	if(z==0){
		if(y%2==1) cout<<y<<" "<<n;
		else cout<<y<<" "<<1;
	}else{
		if(y%2==1) cout<<y+1<<" "<<n-z+1;
		else cout<<y+1<<" "<<z;
	}
	return 0;
}
