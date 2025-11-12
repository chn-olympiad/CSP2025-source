#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	string one,two;
}s[200005];
map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].one>>s[i].two;
		mp[s[i].one]=s[i].two;
	}
	for(register int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(register int i=0;i<a.length();i++){
			string lol="";
			for(register int j=i;j<a.length();j++){
				lol+=a[j];
				if(mp[lol]!=""){
					string neww1="",neww2="";
					neww1=a.substr(0,i);
					neww2=a.substr(j+1,a.length()-j+2);
					if(neww1+mp[lol]+neww2==b) ans++;
					//cout<<neww1<<" "<<mp[lol]<<" "<<neww2<<"*\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
16:36 O(q*l2*l2)?
*/
