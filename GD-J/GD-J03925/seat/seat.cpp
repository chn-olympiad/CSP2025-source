#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n && y%2==1){
			y++;
		}
		else if(x==1 && y%2==0){
			y++;
		}
		else if(y%2==1){
			x++;
		}
		else{
			x--;
		}
	}
}
