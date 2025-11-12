#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans=0;
string s1,s2,s3;
map<string,int> m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int u=0,r=0;
		int r2;
		for(;u<s1.size();u++){
			if(s1[u]!=s2[u]){
				break;
			}
		}
		for(r=s1.size(),r2=s2.size();r>=0;r--,r2--){
			if(s1[r]!=s2[r2]) break;
		}
		for(int j=u;j<=r;j++) s3+=s1[j];
		s3=s3+"|";
		for(int j=u;j<=r2;j++) s3+=s2[j];
		m[s3]++;
		s3="";	
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		int u=0,r=0;
		int r2;
		for(;u<s1.size();u++){
			if(s1[u]!=s2[u]){
				break;
			}
		}
		for(r=s1.size()-1,r2=s2.size()-1;r>=0;r--,r2--){
			if(s1[r]!=s2[r2]) break;
		}
		for(int j=u;j<=r;j++) s3+=s1[j];
		s3=s3+"|";
		for(int j=u;j<=r2;j++) s3+=s2[j];
		cout<<m[s3]<<'\n';
		s3="";
	}
	return 0;
}

