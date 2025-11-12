#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[100007],ans,t,x=1,y=1,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j];
		}
	}
	ans=a[1];
	t=n*m;
	sort(a+1,a+n*m+1);
	while(t--){
		p++;
		if(a[p]==ans) {
			cout<<x<<' '<<y;
			return 0;
		}
		int d;
		if(y%2==1) d=1;
		else d=-1;
		x+=d;
		if(x<1||x>n){
			x=(x+n)%n;
			y++;
		}
	}
	return 0;
}