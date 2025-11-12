#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int x,y,cnt;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	x=1,y=1,cnt=1;
	while(1){
		if(x<=0) y++,x=1;
		if(x>n) y++,x=n;
		if(a[cnt]==s){
			cout<<y<<' '<<x;
			return 0;
		}
		cnt++;
		if(y%2==1) x++;
		else x--;
	}
	return 0;
}
