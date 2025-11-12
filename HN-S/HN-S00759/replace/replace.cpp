#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s[200005][2];
unordered_map<string,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		mp[s[i][0]]=i;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int len=s1.size();
		int L=1e9,R=-1e9;
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]){
				L=min(L,i);
				R=max(R,i);
			}
		}
		ll ans=0;
		for(int i=0;i<=L;i++){
			string str1=s1.substr(i,R-i);
			string str2=s2.substr(i,R-i);
			for(int j=R;j<len;j++){
				str1+=s1[j];
				str2+=s2[j];
				if(mp.count(str1)){
					if(str2==s[mp[str1]][1]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
