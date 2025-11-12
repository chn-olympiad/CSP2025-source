#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e5+5;
const int mod1=998244353;
const int base1=131;
int n,m;
long long h1[N],h2[N],b1[N];
string a[N],b[N];
string s1,s2;
map<string,int>mp;
int query1(int l,int r){
	if(l>r)return 0;
	return (h1[r]-h1[l-1]*b1[r-l+1]%mod1+mod1)%mod1;
}
int query2(int l,int r){
	if(l>r)return 0;
	return (h2[r]-h2[l-1]*b1[r-l+1]%mod1+mod1)%mod1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mp[a[i]]=i;
//		cout<<l<<' '<<r<<'\n';
	}
	b1[0]=1;
	for(int i=1;i<=n;i++){
		b1[i]=b1[i-1]*base1%mod1;
	}
	while(m--){
		cin>>s1>>s2;
		s1=' '+s1;
		s2=' '+s2;
		int ans=0,n=s1.size()-1;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		h1[0]=0;
		h2[0]=0;
		for(int i=1;i<=n;i++){
			h1[i]=(h1[i-1]*base1+s1[i]-'0')%mod1;
			h2[i]=(h2[i-1]*base1+s2[i]-'0')%mod1;
		}
		for(register int i=1;i<=n;i++){
			string ss1,ss2;
			for(int len=1;i+len-1<=n;len++){
				ss1+=s1[i+len-1];
				ss2+=s2[i+len-1];
				if(query1(1,i-1)==query2(1,i-1)&&query1(i+len,n)==query2(i+len,n)&&b[mp[ss1]]==ss2){
					ans++;
				}
//				if(s1.substr(0,i)==s2.substr(0,i)&&s1.substr(i+len,s1.size()-i-len)==s2.substr(i+len,s2.size()-i-len)
//				&&b[mp[s1.substr(i,len)].first]==s2.substr(i,len)){
//					ans+=mp[s1.substr(i,len)].second;
//				}
			}
		}
		cout<<ans<<'\n';
	}
}
