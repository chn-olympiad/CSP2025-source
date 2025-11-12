#include <bits/stdc++.h>
using namespace std;
int a[100000];
int cnt=1,r,n,m,f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	for(int i=2;i<=n*m;i++){
		if(a[i]>r){
			f++;
		}
	}
	int x=1,y=1;
	while(1){
		if(cnt==f){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2==1){
			x++;
			cnt++;
		}
		if(x>n){
			y++;
			x--;
			continue;
		}
		if(y%2==0){
			x--;
			cnt++;
		}
		if(x<1){
			y++;
			x++;
			continue;
		}
	}
	return 0;
}
