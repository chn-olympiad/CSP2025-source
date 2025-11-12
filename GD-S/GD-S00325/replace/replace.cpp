#include<bits/stdc++.h>
using namespace std;
int n,T,m,ans;
string s,t;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++) cin>>s>>t,mp[s]=t;
	while(T--){
		cin>>s>>t;m=s.size(),s=" "+s;ans=0;
		for(int i=0;i<=m;i++){
			for(int j=1;j<=m-i+1;j++){
				string s1=s.substr(j,i),s2=s.substr(1,j-1),s3=s.substr(j+i);
				if(mp[s1]!=""){
					if(s2+mp[s1]+s3==t) ans++;
				}
			}  
		}
		cout<<ans;
	} 
	return 0;
} 
