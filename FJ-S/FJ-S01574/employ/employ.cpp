#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m;
int ans;
string s;
int an[N];
int a[N];
int st[N];
int sum[N];
void dfs(int step,int num) {
	if(step==n+1) {
		if(num>=m) {
			ans=(ans+1)%mod;
//			for(int i=1; i<=n; i++) {
//				cout<<an[i]<<' ';
//			}
//			cout<<'\n';
//			cout<<num<<'\n';
		}
//		for(int i=1; i<=n; i++) {
//			cout<<an[i]<<' ';
//		}
//		cout<<num;
//		cout<<'\n';
		return;
	}
//	if(num>=m) {
//		int cnt=1;
//		for(int i=1; i<=n-step+1; i++) {
//			cnt*=i;
//		}
//		ans=(ans+cnt)%mod;
//		//if(cnt==120)cout<<cnt<<'\n';
////		for(int i=1; i<step; i++) {
////			cout<<an[i]<<' ';
////		}
////		cout<<'\n';
//		//cout<<num<<'\n';
//		//cout<<ans<<'\n';
//		return;
//	}
	for(int i=1; i<=n; i++) {
		if(st[i])continue;
		int nn=num;
		if(a[i]>sum[step]&&s[step-1]=='1') {
			//cout<<step<<' '<<i<<' '<<a[i]<<' '<<sum[step]<<'\n';
			//cout<<step<<' '<<s[step-1]<<'\n';
//			an[step]=i;
//			st[i]=1;
//			dfs(step+1,num+1);
//			st[i]=0;
//			continue;
			nn++;
		}
		an[step]=i;
		st[i]=1;
		dfs(step+1,nn);
		st[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int flag=1;
	for(int i=0; i<(int)s.size(); i++) {
		if(s[i]!='1') {
			flag=0;
			break;
		}
	}
	if(flag) {
		long long cnt=1;
		for(int i=2; i<=n; i++) {
			cnt*=i;
			cout<<cnt<<'\n';
		}
		cout<<cnt%mod<<'\n';
		return 0;
	}
	for(int i=0; i<(int)s.size(); i++) {
		sum[i+1]=sum[i];
		if(s[i-1]=='0')sum[i+1]++;
		//cout<<sum[i+1]<<'\n';
	}
	sum[1]=0;
	memset(st,0,sizeof(st));
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
