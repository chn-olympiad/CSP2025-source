#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,id,rk;
}a[101];
bool cmp1(node a,node b){
	return a.num>b.num;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ansn,ansm;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp1);
	for(int i=1;i<=n*m;i++){
		a[i].rk=i;
	}
	sort(a+1,a+n*m+1,cmp2);
	ansn=(a[1].rk-1)/n+1;
	if(ansn%2){
		ansm=(a[1].rk-1)%n+1;
	}
	else{
		ansm=n-(a[1].rk-1)%n;
	}
	cout<<ansn<<' '<<ansm;
	return 0;
}
