#include<bits/stdc++.h>
using namespace std;
int s[505],c[505],cnt[505];
long long a[505];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=(i*a[i-1])%mod;
	}
	bool qs=1;
	string ss;
	cin>>ss;
	for(int i=1;i<=n;i++){
		s[i]=ss[i-1]-'0';
		if(s[i]==0)qs=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		int w=n+1;
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				w=i;
				break;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=w)cnt++;
		}
		long long ans=(cnt*a[n-1])%mod;
		if(cnt>0){
			cout<<ans;
		}
		else {
			cout<<0;
		}
	}
	else if(m==n){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				flag=0;
				break;
			}
		}
		if(!flag){
			cout<<0;
			return 0;
		}
		else {
			long long ans=1;
			for(int i=1;i<=n;i++){
				cnt[c[i]]++;
			}
			int now=0;
			for(int i=1;i<=n;i++){
				now+=cnt[i];
				if(now>i*(i+1)/2){
					cout<<0;
					return 0;
				}
			}
		}
	}
	return 0;
}
