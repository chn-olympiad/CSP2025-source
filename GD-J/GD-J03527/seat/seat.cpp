#include<bits/stdc++.h>
using namespace std;
const int N=1e3+8;
int n,m,rs,l=1,r;
int a[N];
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rs=a[1];
	sort(a+1,a+n*m+1,cmp);
	r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>rs){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	int x=l%(n*2),y=l/m+1;
	if(l%m==0){
		y=l/m;
	}
	if(x>n){
		x=n-(x-n)+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
