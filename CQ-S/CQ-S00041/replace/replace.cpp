#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+9,base1=201013,base2=1974581;
int n,q,ll,rr,tot,bj1,l[500005],r[500005],cnt1[500005],cnt2[500005],ans;
string s1,s2,s11[500005],s22[500005],t1[500005],t2[500005];
unordered_map<int,int> mp;
vector<int> e[500005];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ll=0,rr=s1.length()-1;
		for(int j=0;j<s1.length();j++){
			if(s1[j]!=s2[j]) break;
			ll++;
		}
		for(int j=s1.length()-1;j>=0;j--){
			if(s1[j]!=s2[j]) break;
			rr--;
		}
//		cout<<ll<<" "<<rr<<"\n";
		l[i]=ll,r[i]=rr;	
		int x1=1,x2=1;
		for(int j=ll;j<=rr;j++){
			x1=(x1*base1+s1[j]-'a')%mod;
			x2=(x2*base2+s2[j]-'a')%mod;
		}
		int x=(x1+x2)%mod;
		if(mp[x]==0) {
			mp[x]=++tot;
		}
		int now=mp[x];
		e[now].push_back(i);
		s11[i]=s1,s22[i]=s2;
		cout<<x<<"\n";
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s1>>s2;
		ll=0,rr=s1.length()-1;
		for(int j=0;j<s1.length();j++){
			if(s1[j]!=s2[j]) break;
			ll++;
		}
		for(int j=s1.length()-1;j>=0;j--){
			if(s1[j]!=s2[j]) break;
			rr--;
		}
//		cout<<ll<<" "<<rr<<"\n";
		int x1=1,x2=1;
		for(int j=ll;j<=rr;j++){
			x1=(x1*base1+s1[j]-'a')%mod;
			x2=(x2*base2+s2[j]-'a')%mod;
		}
		int x=(x1+x2)%mod;
		if(mp[x]==0) {
			cout<<"0\n";
			break;
		}
		int now=mp[x];
		for(auto u:e[now]){
			int bj=0;
			for(int p=l[u],j=ll;p>=0&&j>=0;p--,j--){
				if(s11[i][p]!=s1[j]){
					bj=1;
					break;
				}  
			}
			for(int p=r[u],j=rr;p<s11[i].length()&&j<s1.length();p++,j++){
				if(s11[i][p]!=s1[j]){
					bj=1;
					break;
				}  
			}
			cout<<i<<" "<<u<<" "<<bj<<"\n";
			if(bj==0) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
