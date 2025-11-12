#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD1=998244353;
const int MOD2=1e9+7;
const int BASE1=13;
const int BASE2=17;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,q; cin>>n>>q;
	map<pair<pair<int,int>,int>,pair<int,int>> mp;
	vector<pair<pair<int,int>,pair<int,int>>> val(n+1,{{0,0},{0,0}});
	vector<pair<int,int>> loc(n+1,{0,0});
	int idx=0;
	auto myhash=[&](string s1,string s2,int id)->void{
		int l=-1,r=-1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		//cout<<s1.substr(l,r-l+1)<<"\n";
		int val11=0,val12=0,val21=0,val22=0;
		for(int i=l;i<=r;i++){
			val11=((val11*BASE1)%MOD1+s1[i])%MOD1;
			val12=((val12*BASE2)%MOD2+s1[i])%MOD2;
			val21=((val21*BASE1)%MOD1+s2[i])%MOD1;
			val22=((val22*BASE2)%MOD2+s2[i])%MOD2;
		}
		val[id]={{val11,val12},{val21,val22}};
		loc[id]={l,r};
	};
	vector<string> str1(n+1," "),str2(n+1," ");
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
		myhash(str1[i],str2[i],i);
	}
	while(q--){
		string s1,s2; cin>>s1>>s2;
		int l=-1,r=-1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		int val11=0,val12=0,val21=0,val22=0;
		for(int i=l;i<=r;i++){
			val11=((val11*BASE1)%MOD1+s1[i])%MOD1;
			val12=((val12*BASE2)%MOD2+s1[i])%MOD2;
			val21=((val21*BASE1)%MOD1+s2[i])%MOD1;
			val22=((val22*BASE2)%MOD2+s2[i])%MOD2;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			pair<pair<int,int>,pair<int,int>> tmp={{val11,val12},{val21,val22}};
			if(val[i]==tmp){
				int ln=loc[i].first,rn=loc[i].second;
				int len=str1[i].size();
				if(l-ln<0||r+len-rn-1>=s1.size()) continue;
				if(str1[i].substr(0,ln)==s1.substr(l-ln,ln)&&str1[i].substr(rn+1,len-rn-1)==s1.substr(r+1,len-rn-1)) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
