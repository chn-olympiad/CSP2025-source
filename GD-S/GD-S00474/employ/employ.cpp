#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,c[N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	bool flg=true;
	for(int i=1;i<=n;i++)
		if(s[i]!='1') flg=false;
	if(flg){
		int tmp=0;
		for(int i=1;i<=n;i++)
			if(c[i]==0) tmp++;
		n-=tmp;
		if(n<m){
			cout<<0;
			return 0;
		}
		else{
			long long ans1=1,ans2=1;
			for(int i=n;i>=n-m+1;i--) ans1=ans1*i%MOD;
			for(int i=n+tmp-m;i>=n;i--) ans2=ans2*i%MOD;
			cout<<ans1*ans2%MOD;
		}
	}
	else cout<<0;
	return 0;
}
