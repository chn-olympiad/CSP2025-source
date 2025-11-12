#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<string>st(n+3);
	for(int i=1;i<=n;i++){
		string s;
		cin>>st[i]>>s;
		mp[st[i]]=s;
	}
	for(int i=1;i<=q;i++){
		int sum=0;
		string str,strr;
		cin>>str>>strr;
		int len=str.size();
		for(int j=1;j<=len;j++){
			string ss="",ans="";
			for(int k=j;k<=len;k++){
				ss+=str[j-1];
				ans+=strr[j-1];
				if(mp[ss]==ans)sum++;
			}	
		}
		cout<<sum<<'\n';
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
