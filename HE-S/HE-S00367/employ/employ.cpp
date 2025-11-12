#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=510;
int n,m;
bool vis[N];
int c[N];
bool f=1;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='1'){
			vis[i]=1;
			cnt++;
		}else{
			f=0;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>0){
			sum++;
		}
	}
	if(f){
		if(sum>=m){
			int ans=1;
			for(int i=1;i<=sum;i++){
				ans=(ans*i)%mod;
			}
			for(int i=1;i<=n-sum;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(cnt<m||sum<m){
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
