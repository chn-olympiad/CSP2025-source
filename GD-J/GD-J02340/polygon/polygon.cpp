#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5050;
const int mod=998244353;
int n,ans,a[N];
void sol(int l,int step,int sum){
	//cout<<l<<" "<<step<<" "<<sum<<'\n';
	for(int i=l;i<=n-step+1;i++){
		if(step==1){
			if(sum>a[i]){
				ans=(ans+1)%mod;
			}
		}
		else{
			sol(i+1,step-1,sum+a[i]);
		}
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		sol(1,i,0);	
	}
	cout<<ans;
	return 0;
} 
