#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 18446744073709551615
int n,q;
string s[1000010][3];
map<string,string>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],mp[s[i][1]]=s[i][2];
	while(q--){
		string s1,s2;
		cin>>s1>>s2; 
		int a=s1.size(),b=s2.size();
		if(s1[0]!=s2[0]&&s1[a-1]!=s2[b-1]&&mp[s1]!=s2){
			cout<<0<<endl;
			continue;
		}
		int pre=0,lst=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s1.find(s[i][1])!=inf){
				int p=s1.find(s[i][1]);
				string x=s1.substr(0,p),z=s1.substr(p+s[i][1].size(),a-p-s[i][1].size()+1);
				if(p==0) x="";
				if(p+s[i][1].size()==a) z="";
				string ss=x+mp[s[i][1]]+z;
				if(ss==s2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
} 
