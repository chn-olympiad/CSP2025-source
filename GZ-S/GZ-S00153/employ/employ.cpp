//GZ-S00153 贵阳雅礼高级中学（贵阳市第九中学） 张宛钰
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans=1;
int n,m,c[510],p[510],t[510],ax=-1,l=0;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		p[c[i]]++;
		ax=max(ax,c[i]);
	}
	t[0]=p[0];
	for(int i=1;i<=ax;i++){
		t[i]=p[i]+p[i-1];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') l++;
		ans=(ans*t[l])%mod;
	}
	cout<<ans<<endl;
	
	return 0;
}
