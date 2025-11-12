#include<bits/stdc++.h>
using namespace std;
int n,m,xx,yy;
struct code{
	int x,e;
}a[105];
int l;
bool cmp(code a,code b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i].x;
	}
	a[1].e=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].e==1){
			l=i;
			break;
		}
	}
	xx=ceil(l*1.0/n);
	if(xx%2==1){
		yy=l%n;if(yy==0)yy=n;
	}else{
		yy=n+1-l%n;
	}
	
	cout<<xx<<" "<<yy;
	return 0;
} 
