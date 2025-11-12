#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a1,now,a[105];
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
	a1=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			now=i;
			break;
		}
	}
	if(now%n!=0){
		y=floor(now/n)+1;
		if(y%2==1) x=now%n;
		else x=n-now%n+1;
	}else{
		y=now/n;
		if(y%2==1) x=n;
		else x=1;
	}
	cout<<y<<" "<<x;
	return 0;
}
