#include<bits/stdc++.h>
using namespace std;
const int N=6000;
const long long mod=998244353;
long long n,a[N];long long ans,sum=0;
//vector<int>g;
void dfs(int k,int cnt,long long ma){
	if(k>n)return ;
	
	dfs(k+1,cnt,ma);
	cnt++;
	ma=max(a[k],ma);
	sum+=a[k];
	//cout<<k<<" "<<cnt<<" "<<ma<<" "<<" "<<sum<<" "<<ans<<endl;
	if(sum>2*ma&&cnt>=3)ans=(ans+1)%mod;
	dfs(k+1,cnt,ma);
	sum-=a[k];
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(n<3){
		cout<<0;
		return 0;
	}
	else{
	dfs(1,0,0);
	cout<<ans;
	}
	return 0;
}