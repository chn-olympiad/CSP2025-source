#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,sx=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<y<<' '<<x;
			return 0;
		}
		
		if(x==n && sx==1){
			y++;
			sx=0;
		}
		else if(x==1 && sx==0){
			y++;
			sx=1;
		}
		else {
			if(sx==1)x++;
			else x--;
		}
	}
	return 0;
}
