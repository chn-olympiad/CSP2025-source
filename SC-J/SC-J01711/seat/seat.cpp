#include<bits/stdc++.h>
using namespace std;
long long a[1000005],x,y,s,n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		a[i]*= -1;
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	x=y=1;
	for(int i=1;i<=n*m;i++){
		if(s==a[i]){
			cout<<x<<' '<<y;
			return 0;
		}
		if((x&1)==0){
			y--;
			if(y==0) {
				y=1;
				x++;
			}
		}
		else{
			y++;
			if(y==n+1) {
				y=n;
				x++;
			}
		}
	}
	return 0;
} 