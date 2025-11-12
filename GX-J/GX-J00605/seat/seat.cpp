#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],x=1,y=1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			break;
		}
		x++;
		if(x>n){
			x=1;
			y++;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
