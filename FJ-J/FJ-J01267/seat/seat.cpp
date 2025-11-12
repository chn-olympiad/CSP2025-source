#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,s;
}a[1005];
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	int flag=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			flag=i;
			break;
		}
	}
	int x,y;
	if(flag%n==0){
		x=flag/n;
		y=n;
	}
	else{
		x=flag/n+1;
		y=flag%n;
	}
	if(x%2==0) cout<<x<<" "<<n-y+1;
	else cout<<x<<" "<<y;
	return 0;
}

