#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int d=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=0,y=1;
	for(int i=1;i<=n*m;i++){
		if(y%2==1){
			x++;
			if(x>n)x=n,y++;
		}
		else{
			x--;
			if(x<1)x=1,y++;
		}
		if(a[i]==d){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
}
