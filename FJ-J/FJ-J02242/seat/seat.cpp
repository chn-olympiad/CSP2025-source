#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,cnt1,x=1,y=1;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	cnt1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		cnt++;
		if(a[i]==cnt1){
			break;
		}
	}
	if(cnt>n){
		if(cnt%n==0){
			y=cnt/n;
		}
		else{
			y=cnt/n+1;
		}
	}
	if(y%2==0&&y%3!=0){
		x=cnt-(y-1)*n;
		if(x==1){
			x=n;
		}
		else{
			x=n-x+1;
		}
	}
	else{
		x=cnt-(y-1)*n;
	}
	cout<<y<<" "<<x;
	return 0;
}
