#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
int a[11];
int arr(int n,int m){
	int res=1;
	for (int i=m+1;i<=n;i++) res=res*i%p;
	return res;
}

void solve(){
	int n,m;cin>>n>>m;
	bool f=1;
	int cnt=n;
	string s;cin>>s;
	vector<int> c(n+1),sum(n+1);
	for (int i=1;i<=n;i++) cin>>c[i];
	s=' '+s;/* 
	for (int i=1;i<=n;i++){
		if (s[i]!='1'){
			f=0;
			break;
		}
	}
	if (f){
		for (int i=1;i<=n;i++) if (c[i]==0) cnt--;
//		cout<<cnt<<endl;
		if (cnt<m) cout<<0<<endl;
		else{
			int ans=1;
			for (int i=1;i<=n;i++) ans=ans*i%p;
			cout<<ans<<endl;
		}
	}
	else*/
	sort(c.begin()+1,c.end());
	for (int i=1;i<=n;i++){
		if (s[i]=='0') sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	if (n<=10){
		int ans=0;
		for (int i=1;i<=n;i++) a[i]=i;
		do{
			int cc=0,tmp=0;
			for (int i=1;i<=n;i++){
				if (s[i]=='0'||c[a[i]]<=cc) cc++;
				else tmp++;
			}
			if (tmp>=m) ans++;
		}while(next_permutation(a+1,a+1+n));
		cout<<ans<<endl;
		return;
	}
	if (m==n){
		for (int i=1;i<=n;i++){
			if (s[i]=='0'||c[i]==0){
				cout<<0<<endl;
				return;
			}
		}
		cout<<1<<endl;
		return;
	}
	if (m==1){
		if (sum[n]==0){
			cout<<0<<endl;
			return;
		}
		
	}
	cout<<0<<endl;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	fr[0]=1,fr[1]=1;
//	for (int i=2;i<=500;i++) fr[i]=i*fr[i-1]%p;
//	for (int i=1;i<=500;i++) cout<<fr[i]<<endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int t=1;
	while (t--) solve();
	return 0;
}

