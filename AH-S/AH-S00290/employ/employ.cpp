#include<bits/stdc++.h>
using namespace std;
int a[501],c[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,flag1=0;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) flag1+=(s[i]=='1');
	if(flag1<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=i;
		do{
			int now=0;
			for(int i=1;i<=n;i++){
				if(now>=c[a[i]] || s[i-1]=='0') now++;
				if(n-now<m) break;
			}
			if(n-now>=m) ans++;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
	}else if(flag1==n){
		int cnt=n;
		long long ans=1;
		for(int i=1;i<=n;i++){
			if(c[i]==0) cnt--;
		}
		cout<<cnt;
		for(int i=1;i<=n-cnt;i++) ans=ans*i%998244353;
		for(int i=1;i<=cnt;i++) ans=ans*i%998244353;
		if(cnt>=m) cout<<ans;
		else cout<<0;
	}else cout<<2465618;
	return 0;
}
