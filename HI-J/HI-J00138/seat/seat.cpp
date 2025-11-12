#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e2+5;
int a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int xr=a[1];
	sort(a+1,a+n*m+1);
	int k=lower_bound(a+1,a+n*m+1,xr)-a-1;
	k=n*m-k;
	int x=0,y=1;
	bool f=0;
	for(int i=1;i<=k;i++){
		if(f==0)x++;
		else x--;
		if(x>n){
			f=1;
			x=n; y++;
		}else if(x<1){
			f=0;
			x=1; y++;
		}
	}
	cout<<y<<' '<<x;
	
	return 0;
}
