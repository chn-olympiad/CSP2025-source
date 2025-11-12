#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct node{
	long long num,fl;
}; 
node a[150];
long long n,m,xx,yy,y,x;
bool cmp(node q,node e){
	return q.num>e.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].fl=0;
	}
	a[1].fl=1;
	sort(a+1,a+n*m+1,cmp);
	xx=0;
	yy=0;
	for(int i=1;i<=m*n;i++){
		if(a[i].fl){
			long long xx=i/n,yy=i%n;
			if(yy==0) xx--;
			if(xx%2==0){
				y=yy;
				x=xx+1;
				if(y==0) y=n;
				cout<<x<<" "<<y;
			}
			else{
				y=n-yy+1;
				x=xx+1;
				if(y==0) y=n;
				cout<<x<<" "<<y;
			}
		}
	}
	return 0;
}