#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long n,q;
string s[200005][3],s1,s2;
long long ans;
map<pair<string,string>,bool>mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[{s[i][1],s[i][2]}]=1;
	}
	while(q--){
		cin>>s1>>s2;
		int ls1=s1.size(),ls2=s2.size();
		if(ls1!=ls2){
			cout<<0<<"\n";
			continue;
		}
		s1="*"+s1;
		s2="*"+s2;
		s1=s1+"*";
		s2=s2+"*";
		for(int i=0;i<=ls1-2;i++){
			if(s1[i]!=s2[i]) break;
			string ss1="",ss2="",sz1="",sz2="";
			bool f=true;
			for(int j=i+1;j<=ls1;j++){
				ss1+=s1[j];
				ss2+=s2[j];
				for(int k=j+1;k<=ls1+1;k++){
					if(s1[k]!=s2[k]){
						f=false;
						break;
					}
				}
				if(!f){
					f=true;
				continue;	
				}
				if(mp[{ss1,ss2}]) ans++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}