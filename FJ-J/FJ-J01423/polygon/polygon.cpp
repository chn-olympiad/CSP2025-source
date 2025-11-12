#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n;
int a[5005];
int b[5005];
map<int ,int > mp[5005];

long long dfs(int ii,int num) {
	if(mp[ii][num]>0) return mp[ii][num];
	if(ii<=0) {
		if(num<0) return 1;
		return 0;
	}
	if(b[ii]<=num) return 0;
	long long ans=(dfs(ii-1,num)+dfs(ii-1,num-a[ii]))%mod;
	mp[ii][num]=ans;
//	cout<<ii<<' '<<num<<endl;
//	cout<<dfs(ii-1,num)<<' '<<dfs(ii-1,num-a[ii])<<endl<<endl;
	return ans;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	bool flag=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>=2) flag=0;
	}
	if(flag) {
		b[1]=1;
		long long ans=0;
		for(int i=2; i<=n; i++) b[i]=b[i-1]+i;
		for(int i=3; i<=n; i++) {
			for(int j=1; j<=i-2; j++) ans=(ans+b[j])%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		b[i]=b[i-1]+a[i];
	}
	long long ans=0;
	for(int i=3; i<=n; i++) {
		ans=(ans+dfs(i-1,a[i]))%mod;
	}
	cout<<ans;

	return 0;
}
/*
5
2 2 3 8 10
*/
