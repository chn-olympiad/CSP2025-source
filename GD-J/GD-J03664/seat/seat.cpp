#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001][1001],b[100001],x=1,y=1,t,f;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) cin>>b[i];
	t=b[1];
	sort(b+1,b+1+n*m);
	for(long long i=n*m;i>=1;i--){
		a[x][y]=b[i];
		if(a[x][y]==t){
			cout<<y<<' '<<x;
			return 0;
		}
		if(f==0) x++;
		if(x>n){
			 x=n,f=1,y++;
			 continue;
		} 
		else if(f==1)x--;
		if(x==0){
			 x=1,f=0,y++;
			 continue;
		} 	
	}
	return 0;
}
