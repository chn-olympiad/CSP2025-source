#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int n,m;
int p[N],f[N],a[N];
long long ans=0;
string s;
int cs=0;
long long dt[N];
void dfs(int x){
	if(x>n){
		cs++;
//		for(int i=1; i<=n; i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<'\n';
		int cnt=0,sum=0;
		for(int i=1; i<=n; i++){
			if(cnt>=a[p[i]]||s[i]=='0'){
				cnt++;
			}
			else{
				sum++;
			}
		}
		if(sum>=m)ans++,ans%=mod;
		return ;
	}
	for(int i=1; i<=n; i++){
		if(f[i]==0){
			f[i]=1;
			p[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int flag=0;
	cin>>n>>m;
	if(m==n){
		cout<<0;
		return 0;
	}
	cin>>s;
	s=" "+s;
	for(int i=1; i<=n; i++){
		if(s[i]=='0'){
			flag=1;
			break;
		}
	}
	int k=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]==0)k++;
	}
	if(m==1){
		int cntt=0;
		int num=0;
		for(int i=1; i<=n; i++){
			if(s[i]=='1')cntt++;
		}
		for(int i=1; i<=n; i++){
			if(a[i]>cntt)num++;
		}
		int aa=1;
		for(int i=1; i<=num; i++){
			aa*=i;
			aa%=mod;
		}
		cout<<aa;
		return 0;
	}
//	if(flag==0){
//		if(k<m){
//			cout<<0;
//			return 0;
//		}
//		dt[1]=1;
//		for(int i=2; i<=501; i++){
//			dt[i]=(dt[i-1]*i)%mod;
//		}
//		cout<<dt[n];
//		return 0;
//	}
	dfs(1);
	cout<<ans;
//	cout<<'\n'<<cs;
	return 0;
}
/*

*/
