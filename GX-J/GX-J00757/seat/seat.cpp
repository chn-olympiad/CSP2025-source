#include <bits/stdc++.h>
using namespace std;
struct ab{
	int s;
	bool id;
};
bool cmp(ab a,ab b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,d;
	ab a[200];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].s;
		a[i].id=0;
	}
	a[0].id=1;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i].id==1){d=i+1;break;}
	}
	int x,y;
	x=ceil(d*1.0/n);
	if(x%2==1)y=d%n;
	if(y==0)y=n;
	if(x%2==0){y=d%n;if(y==0)y=n;y=n-y+1;}
	cout<<x<<' '<<y;
	return 0;
}
