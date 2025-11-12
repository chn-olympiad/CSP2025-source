#include <bits/stdc++.h>
using namespace std;
const int MN=200501;
int n,q,cnt,ans;
unordered_map<string,string>mp;
string s1,s2,s[MN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		mp[s2]=s1;
		s[++cnt]=s1,s[++cnt]=s2;
	}for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int len=s1.size();ans=0;
		for(int j=1;j<=cnt;j++){
			if(s[j].size()>len)continue;
			string s3=mp[s[j]],s4=s1;
			int c=0;bool bo=0;
			while(1){
				int d=s4.find(s[j],c);
				if(d==-1||bo)break;bo=1;
				for(int i=0;i<s3.size();i++){
					if(s3[i]!=s2[i+d])bo=0;
				}if(bo)for(int i=0;i<s3.size();i++){
					s4[i+d]=s3[i];
				}c=d+s3.size();
			}if(s2==s4)ans++;
		}cout<<ans<<'\n';
	}return 0;
}

