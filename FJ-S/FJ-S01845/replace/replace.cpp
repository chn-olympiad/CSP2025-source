#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=5e6+10,mod=998244353;

int n,q;
string s1[N],s2[N],t1,t2;
int hs[M],hs1[M][2],hs2[M];
int dis[N],len[N];
int m3[M];
map<pair<int,int>,vector<int>>mp;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	m3[0]=1;
	for(int i=1;i<=M-5;i++)m3[i]=m3[i-1]*31%mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;i++){
		int l=0,r=s1[i].size()-1;
		while(s1[i][l]==s2[i][l]&&l<s1[i].size())l++;
		while(s1[i][r]==s2[i][r]&&r>-1)r--;
		if(l==s1[i].size())continue;
		for(int j=0;j<s1[i].size();j++)hs[i]=(hs[i]*31%mod+s1[i][j]-'a')%mod;
		for(int j=l;j<=r;j++)hs1[i][0]=(hs1[i][0]*31%mod+s1[i][j]-'a')%mod;
		for(int j=l;j<=r;j++)hs1[i][1]=(hs1[i][1]*31%mod+s2[i][j]-'a')%mod;
		dis[i]=l,len[i]=s1[i].size()-1-l+1;
		mp[{hs1[i][0],hs1[i][1]}].push_back(i);
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		hs2[0]=t1[0]-'a';
		for(int i=1;i<t1.size();i++)hs2[i]=(hs2[i-1]*31%mod+t1[i]-'a')%mod;
		int l=0,r=t1.size()-1;
		while(t1[l]==t2[l]&&l<t1.size())l++;
		while(t1[r]==t2[r]&&r>-1)r--;
		int hs3[2];
		hs3[0]=hs3[1]=0;
		for(int i=l;i<=r;i++)hs3[0]=(hs3[0]*31%mod+t1[i]-'a')%mod;
		for(int i=l;i<=r;i++)hs3[1]=(hs3[1]*31%mod+t2[i]-'a')%mod;
		int ans=0;
		for(auto i:mp[{hs3[0],hs3[1]}]){
			int st=l-dis[i],ed=l+len[i]-1;
			if(st<0||ed>=t1.size())continue;
			int hs4=hs2[ed];
			if(st)hs4=(hs4-hs2[st-1]*m3[ed-st+1]%mod+mod)%mod;
			if(hs4==hs[i])ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
