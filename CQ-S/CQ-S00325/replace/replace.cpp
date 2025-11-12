#include<bits/stdc++.h>
using namespace std;
int n,m;string s1,s2;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;	
	}
	while(m--){
		cin>>s1>>s2;int len=s1.size(),ans=0;
		int l=0,r=0;s1=' '+s1;s2=' '+s2;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				if(!l) l=i;
				r=max(r,i);
			}
		}
		for(int i=1;i<=l;i++){
			for(int j=len-i+1;i+j-1>=r;j--){
				string d=s1.substr(i,j),p=s2.substr(i,j);
				if(mp[d]==p) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
20pts
*/

