#include<bits/stdc++.h>
using namespace std;
int n,m,r,cnt;
struct ee{
	int x,y,s;
}a[1005];
bool cmp(ee xx,ee xy){
	if(xx.s!=xy.s){
		return xx.s>xy.s;
	}
	return xx.s<xy.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1].s=r;
	for(int i=2;i<=m*n;i++){
		cin>>a[i].s;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			cnt++;
			if(j%2==1){
				a[cnt].y=i;
				a[cnt].x=j;
			}
			else{
				a[cnt].y=n-i+1;
				a[cnt].x=j;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].s==r){
			cout<<a[i].x<<" "<<a[i].y;
		}
	}
}
