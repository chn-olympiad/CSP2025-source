#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,p,x,y;
struct node{
	int b,cnt;
}a[N];
bool cpp(node c,node d){
	return c.cnt>d.cnt;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cnt;
		a[i].b=i;
	}
	sort(a+1,a+n*m+1,cpp);
	for(int i=1;i<=n*m;i++){
		if(a[i].b==1){
			p=i;
			break;
		}
	}
	if(p%n>0){
		y=p/n+1;
		if(y%2>0){
			x=p%n;
		}else{
			x=n-p%n+1; 
		}
	}else{
		y=p/n;
		if(y%2>0){
			x=n;
		}else{
			x=1;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}

