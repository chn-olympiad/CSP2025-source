#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001],x=1,y=1,d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int s=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			cout<<x<<' '<<y;
			return 0;
		}if(y+d>n||y+d<1)x++,d*=-1;
		else y+=d;
	}
	return 0;
}