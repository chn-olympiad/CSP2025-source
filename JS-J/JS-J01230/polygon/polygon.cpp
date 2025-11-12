#include<bits/stdc++.h>
using namespace std;
int n;
long long a[5010],vis[10009][5010];
long long ans;
const int mod=998244353;
long long dfs(int pos,int sum,int maxx,int cnt){
	if(pos>n+1) return 0;
	int cmp=0;
	if(cnt>=3){
		if(sum>maxx*2&&vis[sum][cnt]==0){
			//cout<<sum<<endl;
			cmp++;
			vis[sum][cnt]=1;
		}
	}
	cmp+=dfs(pos+1,sum,maxx,cnt);
	cmp+=dfs(pos+1,sum+a[pos],a[pos],cnt+1);
	return cmp%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3) cout<<0;
	else if(n==3){
		int sum;
		sum=a[1]+a[2]+a[3];
		if(sum>a[3]*2) cout<<1;
		else cout<<0;
	}else{
		cout<<dfs(1,0,0,0);
	}
	//cout<<ans%mod;
	return 0;
}
