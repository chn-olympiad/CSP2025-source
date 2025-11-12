#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p=131;
int n,q;
ull tp[5000001];
map<pair<ull,ull>,int> mp; 
ull gethash(string s){
	int len=s.length();
	ull now=0;
	for(int i=0;i<len;i++){
		now=now*p+(s[i]-'a'+1);
	}
	return now;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		mp[{gethash(s1),gethash(s2)}]++;
	}
	tp[0]=1;
	for(int i=1;i<=2000000;i++)tp[i]=tp[i-1]*p;
	while(q--){
		string s1,s2;cin>>s1>>s2;
		int len=s1.length(),mn=0,mx=0,ans=0;
		if(len!=s2.length()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]){
				if(!mn)mn=i;
				mx=i;
			}
		}
		ull d1=0,d2=0;
		for(int i=mn;i<=mx;i++)d1=d1*p+(s1[i]-'a'+1),d2=d2*p+(s2[i]-'a'+1);
		for(int i=mx+1;i<=len;i++){
			ull f1=d1,f2=d2;
			for(int j=mn-1;j>=0;j--){
				if(mp.find({f1,f2})!=mp.end())ans+=mp[{f1,f2}];
				f1=f1+tp[i-j-1]*(s1[j]-'a'+1);
				f2=f2+tp[i-j-1]*(s2[j]-'a'+1);
			}
			if(mp.find({f1,f2})!=mp.end())ans+=mp[{f1,f2}];
			if(i==len)break;
			d1=d1*p+(s1[i]-'a'+1),d2=d2*p+(s2[i]-'a'+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
