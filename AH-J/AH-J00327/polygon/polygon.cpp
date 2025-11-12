#include<bits/stdc++.h>
using namespace std;
long long n;
long long cnt=0;
long long a[5000+10],f[5000+10];
vector<long long> ans;
void dfs(long long now,long long num,long long pi){
	if(now>num){
		long long maxn=0,sum=0;
		for(int i=0;i<ans.size();i++){
			maxn=max(maxn,ans[i]);
			sum+=ans[i];
		}
		if(sum>2*maxn){
			cnt++;
		}
		return ;
	}
	for(long long i=pi+1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			ans.push_back(a[i]);
			dfs(now+1,num,i);
			ans.erase(ans.begin()+ans.size()-1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long mx=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		if(n<=2){
			cout<<0;
			return 0;
		}
		long long sum=1;
		long long p=1;
		long long num=n;
		for(long long i=1;i<=n-3;i++){
			p*=i;
			sum+=(num/p);
			num*=(n-i);
			p%=998244353;
			sum%=998244353;
			num%=998244353;
		}
		cout<<sum;
		return 0;
	}
	for(long long i=3;i<=n;i++){
		dfs(1,i,0);
	}
	cout<<cnt%998244353;
	return 0;
} 
