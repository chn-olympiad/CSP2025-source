#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int num,id;
}a[105];
bool cmp(node x,node y){
	return x.num>y.num;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+(n*m)+1,cmp);
	int prdr=0;
	for(int i=1;i<=(n*m);i++){
		if(a[i].id==1){
			prdr=i;
			break;
		}
	}
	int c=0,r=0;
	c=prdr/n;
	r=prdr%n;
	if(c%2==0){
		if(c*n==prdr){
			cout<<c<<" "<<1;
			return 0;
		}
		cout<<c+1<<" "<<r;
	}
	else{
		if(c*n==prdr){
			cout<<c<<" "<<m;
			return 0;
		}
		cout<<c+1<<" "<<m-r+1;
	}
	return 0;
}
