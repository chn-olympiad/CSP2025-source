#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long 
string s[200010][10];
string t[10];
map<string,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		mp[s[i][0]]=i;
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		int len=t[0].size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				string str=t[0].substr(i,j-i+1);
				if(mp[str]){
					string sstr=s[mp[str]][1];
					string st0="",st1="";
					if(i)st0=t[0].substr(0,i-1);
					if(j!=len-1)st1=t[0].substr(j);
					string st=st0+sstr+st1;
					if(st==t[1])ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
