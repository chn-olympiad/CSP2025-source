#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
int n,m,a[N],cnt=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	for(int i=1;i<=m;i++){
		if(cnt>n) cnt-=n;
		else{
			if(i%2==1){
				cout<<i<<" "<<cnt;
				return 0;
			}
			else{
				cout<<i<<" "<<n-cnt+1;
				return 0;
			}
		}
	}
	return 0;
} 