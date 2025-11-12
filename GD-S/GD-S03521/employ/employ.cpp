#include<bits/stdc++.h>
using namespace std;
long long ans,p=998244353;int l,n,a[510],v[510];string s;
void f(int rs,int ls,int fs,int ts){
	if(rs==n){
		if(ls>=l)ans++;
	return;}
	ans%=p;
	for(int i=1;i<=n;i++){
		if(v[i]==1)continue;
		v[i]=1;
		if(fs>=a[i]||s[ts]=='0')f(rs+1,ls,fs+1,ts+1);
		else f(rs+1,ls+1,fs,ts+1);
		v[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>l>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(0,0,0,0);ans%=p;cout<<ans;
	return 0;
}

