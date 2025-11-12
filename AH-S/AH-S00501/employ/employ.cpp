#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
int a[N],id[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		id[i]=i;
		cin>>a[i];
	}
	bool fa=1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			fa=0;
			break;
		}
	}
	int tn=n;
	for(int i=1;i<=n;i++){
		if(a[i]==0) tn--;
	}
	if(tn<m){
		cout<<0<<endl;
		return 0;
	}
	if(fa){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if(m==1){
		int ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				int l=lower_bound(a+1,a+n+1,i)-a;
				ans+=(n-l+1);
				for(int i=n-1;i>=1;i--){
					ans=ans*i%mod;
				}
				break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	int ans=0;
	do{
		int get=0,out=0;
		for(int i=1;i<=n;i++){
			if(a[id[i]]<=out){
				out++;
				continue;
			}
			if(get+n-i+1<m) break;
			if(get>=m) break;
			if(s[i]=='1') get++;
			if(s[i]=='0') out++;
		}
		if(get>=m) ans=(ans+1)%mod;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans<<endl;
	return 0;
}
