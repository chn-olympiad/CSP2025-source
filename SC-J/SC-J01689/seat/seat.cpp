#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1],x;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			x=i;break;
		}
	}
	int l=(x-1)/n+1,h;
	int y=x%n;if(y==0) y=n;
	if(l%2==0){
		h=n-y+1;
	}
	else{
		h=y;
	}
	cout<<l<<" "<<h;
	return 0;
}