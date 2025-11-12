#include<bits/stdc++.h>
using namespace std;
int n,m,sum,p;
struct node{
	int x,id;
}a[1000];
bool cmp(node w,node u){
	return w.x>u.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i].id==1) {
			p=i;
			break;
		}
	}
	int c=(p+n-1)/n;
	int r=p-(c-1)*n;
	if(c&1) cout<<c<<' '<<r;
	else cout<<c<<' '<<n-r+1; 
	return 0;
} 
