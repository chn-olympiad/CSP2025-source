#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,idx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			idx=i;
			break;
		}
	}
	int x=ceil(idx*1.0/n),y;
	if(x%2==1){
		y=idx%n;
		if(y==0){
			y=n;
		}
	}
	else{
		y=n-idx%n+1;
		if(idx%n==0){
			y-=n;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}

