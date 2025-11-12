#include<bits/stdc++.h>
using namespace std;

struct node{
	int data,x;
}a[10000];
bool cmp(node a,node b){
	return a.data>b.data;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
		a[i].x=i;
	}
	
	sort(a+1,a+n*m+1,cmp);
	int num,x,y;
	for(int i=1;i<=n*m;i++){
	if(a[i].x==1){
		num=i;
		break;
	}
	}
	
	//cout<<num<<'\n';
	x=(num+n-1)/n;
	if(x%2==1){
	y=num%n;
	if(y==0) y=n;
	}
	else {
		y=n-num%n+1;
		if(num%n==0) y=1;
	}
	cout<<x<<' '<<y;
    return 0;
}
