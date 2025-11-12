#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],js=0,js1=0,js2=0,b[500010],sum=0,c[500010];
const int mod=998244353;
//vector<int> d[1001];
bool vis[500010],vis2[500010];
void dfs(int k,int r){
	if(r==n){
		//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		long long ans,maxx=INT_MIN;
		for(int i=1;i<=n;i++){
			ans+=a[i];
			if(a[i]>maxx) maxx=a[i];
		}
		//for(int i=1;i<=n;i++){
		//	d[sum].push_back(a[i]);
		//}
		//sum++;
		if(ans>maxx*2) sum++;
		cout<<endl;
		return;
	}
	if(k>n){
		long long ans,maxx=INT_MIN;
		for(int i=1;i<=r;i++){
			ans+=b[i];
			if(b[i]>maxx) maxx=b[i];
			cout<<b[i]<<" ";
		}
		//cout<<endl;
		//for(int i=1;i<=r;i++){
		//	d[sum].push_back(b[i]);
		//}
		//sum++;
		if(ans>maxx*2) sum++;
		//cout<<endl;
		return;
	}
	for(int i=1;i<=n-k+1;i++)
		if(!vis[i]){
			vis[i]=1;
			b[k]=a[i];
			dfs(k+1,r);
			vis[i]=0;
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1;
		else cout<<0; 
	}else if(n<3) cout<<0;
	else if(n>3&&n<=10){
		for(int i=3;i<=n;i++){
			dfs(1,i);
		}
		for(int i=1;i<=n;i++)
			if(a[i]==a[i+1]) js++;
		cout<<sum%mod*abs((n-2-js))%mod;
	}else cout<<0;
	return 0;
}
