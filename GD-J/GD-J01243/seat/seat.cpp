#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e3+10;
long long a[maxn];
void solve(){
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++) cin>>a[i];
	long long R=a[1];
	sort(a+1,a+n*m+1);
	long long x=1,y=1,wz=n*m;
	bool o=true;
	for(;;){	
		if(a[wz]==R){
			cout<<y<<' '<<x;
			break;
		}
		else if(o){
			if(x==n){
				y++;
				o=false;
			}
			else{
				x++;
			}
		}
		else{
			if(x==1){
				y++;
				o=true;
			}
			else{
				x--;
			}
		}
		wz--;
	} 
	return;	
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long T=1;
	//cin>>T
	while(T--){
		solve();
	}
	return 0;
}
