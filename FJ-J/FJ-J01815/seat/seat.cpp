#include<bits/stdc++.h>
using namespace std;
struct c{
	int id,sz;
}a[1005];
bool cmp(c x,c y){
	return x.sz>y.sz;
}
int n,m,t,q,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sz;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) t=i;
	}
	q=t/(2*n);
	w=t%(2*n);
	if(w>n){
		w=n+n-w+1;
		q=q*2+2;
	} else q=q*2+1;
	cout<<q<<' '<<w;
	return 0;
}
