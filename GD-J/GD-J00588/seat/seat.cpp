#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmd(int x,int y){
	return x>y;
}
int my_bin(int x,int n){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<=x) r=mid;
		else l=mid+1;
	}
	return r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+t+1,cmd);
	int y=my_bin(x,t);
	int c=(y-1)/n+1;
	cout<<c<<" ";
	if(c%2==0){
		cout<<n-(y%n)+1;
	}else{
		cout<<(y-1)%n+1;
	}
	return 0;
} 
