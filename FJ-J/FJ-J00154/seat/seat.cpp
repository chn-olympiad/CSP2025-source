#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct node{
	int name;
	int id;
}a[N];
int c[1005][1005];
bool cmp(node aa,node bb){
	return aa.name>bb.name;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].name;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) p=i; 
	}
	int x=p/n;
	int xx=p%n;
	if(x%2==1){
		if(xx==0){
			cout<<x<<" "<<n;
		}
		else{
			cout<<x+1<<" "<<n-xx+1;
		}
	}
	else{
		if(xx==0) cout<<x<<" "<<1;
		else cout<<x+1<<" "<<xx;
	}
	return 0;
}
