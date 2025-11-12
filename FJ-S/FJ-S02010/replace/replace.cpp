#include<iostream>
#include<cstring>
#include<utility>
#include<map>
#define int long long
using namespace std;
const int base1=131,mod1=998244853,base2=199,mod2=1e9+9;
int n,q;
char s1[(int)5e6+5],s2[(int)5e6+5];
map<pair<pair<int,int>,pair<int,int>>,int> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1+1>>s2+1;
		int len=strlen(s1+1);
		int h1=0,h2=0,h3=0,h4=0;
		for(int j=1;j<=len;j++){
			h1=(h1*base1+s1[j])%mod1;
			h2=(h2*base2+s1[j])%mod2;
			h3=(h3*base1+s2[j])%mod1;
			h4=(h4*base2+s2[j])%mod2;
		}
		mp[{{h1,h2},{h3,h4}}]++;
	}
	while(q--){
		cin>>s1+1>>s2+1;
		int len=strlen(s1+1);
		if(strlen(s2+1)!=len){
			cout<<"0\n";
			continue;
		}
		int l=1;
		while(l<len&&s1[l]==s2[l]) l++;
		int r=len;
		while(r>1&&s1[r]==s2[r]) r--;
		int ans=0;
		for(int i=1;i<=l;i++){
			int h1=0,h2=0,h3=0,h4=0;
			for(int j=i;j<=len;j++){
				h1=(h1*base1+s1[j])%mod1;
				h2=(h2*base2+s1[j])%mod2;
				h3=(h3*base1+s2[j])%mod1;
				h4=(h4*base2+s2[j])%mod2;
				if(j>=r&&mp.count({{h1,h2},{h3,h4}})) ans+=mp[{{h1,h2},{h3,h4}}];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

