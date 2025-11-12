#include<bits/stdc++.h>
using namespace std;

int n,q;
map<string,string>mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		mp[s2]=s1;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.length(),ans=0;
		s1=" "+s1;
		s2=" "+s2;
		int l=0,r=0;
		for(int i=1;i<=len;i++){
			if(l==0&&s1[i]!=s2[i])l=i;
			if(s1[i]!=s2[i])r=i;
		}
		for(int i=l;i>=1;i--){
			for(int j=r;j<=len;j++){
				string x1="",x2="";
				for(int k=i;k<=j;k++)x1+=s1[k],x2+=s2[k];
				if(mp[x1]==x2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
