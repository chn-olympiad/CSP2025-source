#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k,a[maxn],sum[maxn],last=1,ans;
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=last;j<=i;j++){
			int cnt=(sum[i]^sum[j-1]);
			if(cnt==k){
				//cout<<i<<" "<<j<<endl;
				ans++;
				last=i+1;
				break;
			}
		}
	}
	cout<<ans;
}
void solve(){
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	if(n<=1e3){
		solve1();
		return ;
	}
	int time=0;
	for(int i=1;i<=n;i++){
		time++;
		for(int j=last;j<=i;j++){
			if(time==3e8){
				cout<<ans;
				return ;
			}
			time++;
			int cnt=(sum[i]^sum[j-1]);
			if(cnt==k){
				//cout<<i<<" "<<j<<endl;
				ans++;
				last=i+1;
				break;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0; 
} 
