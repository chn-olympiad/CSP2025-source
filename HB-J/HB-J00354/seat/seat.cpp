#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int ams;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ams=i;
			break;
		}
	}
	int x;
	int y=(ams+n-1)/n;
	int d=ams+n*(y-1)-n/2;
	if(y%2!=0){
		 x=ams-n*(y-1);
	}
	else if(ams-n*(y-1)<=n/2)x=n+1-ams+n*(y-1);
	else x=ams+n*(y-1)-d*2-1;
	cout <<y<<' '<<x;
	return 0;
}
