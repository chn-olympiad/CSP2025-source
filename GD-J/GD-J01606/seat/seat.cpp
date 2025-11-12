#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,a[1145141],xr,mc,bx,x1,y1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++) cin>>a[i];
	xr=a[1];
	sort(a+1,a+1+x*y);
	for(int i=x*y;i>=1;i--){
		if(a[i]==xr){
			mc=x*y-i+1;
			x1=mc/x;
			bx=mc%x;
			if(bx==0){
				if(x1%2==0) y1=1;
				else y1=x;
			}
			else{
				x1++;
				if(x1%2==0) y1=x-bx+1;
				else y1=bx;
			}
			cout<<x1<<" "<<y1;
			return 0;
		}
	} 
}
