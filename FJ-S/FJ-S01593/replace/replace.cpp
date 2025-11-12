#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fs first
#define sc second
const int N=2e5+5;
int n,q;
string a,b;
string x[N],z[N];
pair<string,string> s[N];
map<string,int> mp;
string gg(string s,int l,int r){
	if(l>r)
		return "";
	string tmp="";
	for(int i=l;i<=r;i++)
		tmp+=s[i];
	return tmp;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].fs>>s[i].sc;
		mp[s[i].fs]=i;
	}
	while(q--){
		cin>>a>>b;
		if(a.length()!=b.length()){
			cout<<"0\n";
			continue;
		}
		int na=a.length();
		int ans=0;
		for(int i=0;i<na;i++)
			x[i]=gg(a,0,i-1),z[i]=gg(a,i+1,na-1);
		for(int l=0;l<na;l++){
			string tmp="";
			for(int r=l;r<na;r++){
				tmp+=a[r];
				if(!mp[tmp])
					continue;
				if(x[l]+s[mp[tmp]].sc+z[r]==b)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

