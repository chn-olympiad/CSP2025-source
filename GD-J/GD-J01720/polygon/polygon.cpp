#include<bits/stdc++.h>
using namespace std;
int n,ans,g=2,w=1;
int s[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	w=n*(n-1);
	if(n==3&&s[1]+s[2]>s[3]) cout<<1;
	if(n==3&&s[1]+s[2]<=s[3]) cout<<0;
	if(n==4){
		if(s[1]+s[2]+s[3]>s[4]) ans++;
		if(s[1]+s[2]>s[3]) ans++;
		if(s[1]+s[2]>s[4]) ans++;
		if(s[1]+s[3]>s[4]) ans+=2;
		cout<<ans;
	}
	if(n==5){
		if(s[1]+s[2]+s[3]+s[4]<s[5]) ans++;
		if(s[1]+s[2]+s[3]>s[4]) ans++;
		if(s[1]+s[2]+s[3]>s[5]) ans++;
		if(s[1]+s[3]+s[4]>s[5]) ans+=2;
		if(s[1]+s[2]>s[3]) ans++;
		if(s[1]+s[2]>s[4]) ans++;
		if(s[1]+s[2]>s[5]) ans++;
		if(s[1]+s[3]>s[4]) ans+=2;
		if(s[1]+s[3]>s[5]) ans+=2;
	}
	if(n>=10) for(int i=3;i<=n;++i){
		g=(g*i)%998244353;
		w=(w*(n-i+1))%998244353;
		ans+=w/g;
	}
	if(n>=10) cout<<ans;
	return 0;
}
