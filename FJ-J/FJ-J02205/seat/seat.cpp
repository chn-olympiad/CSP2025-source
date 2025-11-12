#include<bits/stdc++.h>
using namespace std;
struct node{
	int ans,num;
}a[110];
int cmp(node c,node d){
	return c.ans>d.ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tt,f;
	cin>>n>>m;
	tt=n*m;
	for(int i=1;i<=tt;i++){
		cin>>a[i].ans;
		a[i].num=i;
	}
	sort(a+1,a+1+tt,cmp);
	for(int i=1;i<=tt;i++){
		if(a[i].num==1) f=i;
	}
	int fm,fn;
	if(f%n>0) fm=f/n+1;
	else fm=f/n;
	fn=f%n;
	if(!fn) fn=n;
	if(fm%2==1) cout<<fm<<" "<<fn;
	else cout<<fm<<" "<<n-fn+1;
	return 0;
}
