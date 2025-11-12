#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int mod=998244353;
//actually it's my first time to attend CSP exam
//but considering the time and age of mine,it'll be the last time also
//if we use {0,1} in this problem to do with this 4 problems of CSP-S
//for me it's 0 0 0 0
//wait,4pts on m==n?
//wait,20 pts on all one?
bool flag[maxn];
int p[maxn],res;
int n,m,cnt0,cntb,cntof0;
string s;
int k[maxn],c[maxn];
void dfs(int i){
	if(i==n+1){
		int cnt=0,ans=0;
		for(int j=1;j<=n;j++){
//			cout<<p[j]<<' '<<cnt<<' '<<c[p[j]]<<endl;
			if(cnt>=c[p[j]]){cnt++;continue;}
			if(k[j])ans++;
			else cnt++;
		}
//		cout<<endl;
//		cout<<ans<<' '<<cnt<<endl;
		if(ans>=m)res++,res%=mod;
		return;
	}
	for(int j=1;j<=n;j++){
		if(flag[j])continue;
		p[i]=j;
		flag[j]=true;
		dfs(i+1);
		flag[j]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool WHATCANISAY=1;
	bool flag=0;
	for(int i=0;i<n;i++){
		k[i+1]=(s[i]=='1');
		WHATCANISAY&=(s[i]=='1');
		flag|=(s[i]=='1');
		if(!flag&&(s[i]=='0'))cnt0++;
//		cout<<k[i+1]<<' '; 
	}
	for(int i=1;i<=n;i++)cin>>c[i],cntb+=(c[i]>cnt0),cntof0+=(c[i]==0);
	if(WHATCANISAY){
		if(n-cntof0>=m){
			int ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(m==n){
		if(WHATCANISAY&&cntof0==0){
			int ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
//	cout<<endl;
	dfs(1);
	cout<<res<<endl;
	return 0;
}
//score <= (25+48+10+32) = 115
//gua fen qu jian [0,115]
//100% no 1=
//AFO
//luogu UID:513746
//make a friend?
