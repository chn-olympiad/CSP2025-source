#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int n,T,k1,k2,len,ans;
map<string,string> ma;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		ma[s1]=s2;
	}
	while(T--){
		ans=0;
		cin>>s1>>s2;
		len=s1.size();
		if(s1==s2 or len!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<len;i++)
			if(s1[i]!=s2[i]){
				k1=i;
				break;
			}
		for(int i=len-1;i>=0;i--)
			if(s1[i]!=s2[i]){
				k2=i;
				break;
			}
		for(int i=0;i<=k1;i++)
			for(int j=len-1;j>=k2;j--){
				if(ma.find(s1.substr(i,j-i+1))==ma.end())
					continue;
				if(ma[s1.substr(i,j-i+1)]==s2.substr(i,j-i+1)){
					ans++;
					continue;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}
