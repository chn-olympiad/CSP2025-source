#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,x,l,r,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==s){
			x=mid;
			break;
		}else if(a[mid]>s){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	if(x%n==0){
		c=x/n;
	}else{
		c=x/n+1;
	}
	if(c%2==1){
		if(x%n==0){
			r=n;
		}else{
			r=x%n;
		}
	}else{
		if(x%n==0){
			r=1;
		}else{
			r=n-x%n+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
