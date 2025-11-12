#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
const int N=5e3+5;
int n,a[N];
int ans;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0;
		return ;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			ans++;
		}
	}
	int d=0;
	while(d+1<=n-1){
		int c=2;
		while(c+1<=n-1){
			int sum=0;int maxx=-1;
			for(int i=1;i<=n;i++){
				for(int j=i+1+d;j<=n&&j<=i+1+d+c;j++){
					sum+=a[j];
					maxx=max(maxx,a[j]);
				}
			}
			if(sum>2*maxx){
				ans++;
			}
			c++;
		}
		d++;
	}
	cout<<ans;
	return ;
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	return 0;
}	