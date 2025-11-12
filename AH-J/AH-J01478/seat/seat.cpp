#include<bits/stdc++.h>
using namespace std;
int n,m,s,flag;
struct noi{
	int num;
	bool f;
}a[166];
bool cmp(noi x,noi y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].f=0;
	}
	a[1].f=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].f==1){
			flag=i;
			break;
		}
	}
	int x=flag%n;
	double f1=flag;
	int y=ceil(f1/n*1.0);
	if(x==0) x=n;
	if(y%2==0) x=n-x+1;
	cout<<y<<" "<<x;
	return 0;
}
