#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,string>mp;
map<char,int>maxn;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
		int len=a.size();
		maxn[a[0]]=max(maxn[a[0]],len); 
	}
	while(q--){
		string s,s1;
		int cnt=0;
		cin>>s>>s1;
		if(s.size()!=s1.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int i=0;i<s.size();i++)
			if(maxn.count(s[i])){
				string tmp="";
				for(int j=i;j<=s.size();j++)
					{	tmp=tmp+s[j];
						if(mp.count(tmp)&&i+mp[tmp].size()-1<s.size()){
							string v=s;
							for(int k=i;k<s.size()&&k-i<mp[tmp].size();k++)v[k]=mp[tmp][k-i];
							//cout<<s<<" "<<mp[tmp]<<" "<<v<<" "<<s1<<"\n";
							if(v==s1)cnt++;
						}
					}
			}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
