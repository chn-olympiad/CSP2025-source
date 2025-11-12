#include<bits/stdc++.h>
using namespace std;
const int N=111;
int i,j,n,m,x,y,z/* z为0向下，1向上 */,s,a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(cin>>n>>m,i=1;i<=n*m;cin>>a[i++]);
	for(s=a[1],sort(a+1,a+1+n*m,greater<int>()),x=y=i=1;i<=n*m;i++){
		if(s==a[i]) return cout<<y<<' '<<x,0;
		if(z==0)
			if(x==n) y++,z=1;
			else x++;
		else
			if(x==1) y++,z=0;
			else x--;
	}
	return 0;
}
