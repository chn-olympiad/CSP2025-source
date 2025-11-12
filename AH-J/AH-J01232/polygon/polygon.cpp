#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const int P=998244353;
int a[N],n,f[2*N],cnt,b[N],g[2*N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		int ans=0;
		for(int i=1;i<1<<n;i++){
			int mx=0,cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					mx=max(mx,a[j+1]);
					cnt+=a[j+1];
				}
			}
			if(cnt>2*mx) ans++;
		}
		cout<<ans;
	}else{
		cout<<"I can not solve it now! Next year I will come back!";
	}
	return 0;
}
