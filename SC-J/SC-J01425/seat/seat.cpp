#include<bits/stdc++.h>
using namespace std;
int a[110];
struct st{
	int x=0;int y=0;
}s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ans=a[0];
	sort(a,a+n*m);
	int x=1,y=1;//行 列
	int dx=0,dy=0;
	for(int i=n*m-1;i>=0;i--){
		if(x==n){
			if(y%2!=0){
				dx=0,dy=1;
			}
			else{
				dx=-1,dy=0;
			}
		}
		if(x==1){
			if(y%2!=0){
				dx=1,dy=0;
			}
			else{
				dx=0,dy=1;
			}
		}
		s[a[i]].x=x;
		s[a[i]].y=y;
		x+=dx,y+=dy;
	}
	cout<<s[ans].y<<' '<<s[ans].x;
	return 0;
}
