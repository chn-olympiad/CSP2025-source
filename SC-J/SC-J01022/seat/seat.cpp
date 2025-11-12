#include<bits/stdc++.h>
using namespace std;
int a[10010];
int c,r,y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int yye=n*m;
	for(int i=1;i<=yye;i++){
		cin>>a[i];
	}
	int yya=a[1];
	sort(a,a+yye+1);
	for(int i=yye;i>=1;i--){
		if(a[i]!=yya)y++;
		else{
			y++;
			break;
		}
	}
	c=y/n;
	if(y%n!=0)c++;
	if(c%2==1)r=y%(n*2);
	else{
		r=((y-1)%n)-1;
		r=n-r;
	}
	cout<<c<<" "<<r;
	return 0;
}