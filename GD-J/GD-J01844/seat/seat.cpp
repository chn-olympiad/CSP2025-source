#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
struct node{
	int id,ans;
}a[205];
bool cmp(node x,node y){
	return x.ans>y.ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].ans;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			k=i;
		}
	}
	l=n;
	for(int i=1;i<=m;i++){
		if(k<=l){
			if(i%2==1){
				cout<<i<<" "<<k-(l-n);
			}
			else {
				cout<<i<<" "<<l-k+1;
			}
			return 0;
		}
		l+=n;
	}
	return 0;
}
