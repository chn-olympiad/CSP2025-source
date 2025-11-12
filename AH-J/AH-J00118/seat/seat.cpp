#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s=a[1],d;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s) d=i;
	}
	int c,r;
	for(int i=1;i<=m;i++){
		if(d>(i-1)*n&&d<=i*n){
			c=i;
			if(c%2==1) r=d-(i-1)*n;
			else r=i*n-d+1;
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
