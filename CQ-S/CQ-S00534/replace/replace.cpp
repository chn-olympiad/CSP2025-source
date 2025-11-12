#include<bits/stdc++.h>
using namespace std;
int n,q,st,t,mpi,ai[200005];
vector<int>a[200005];
string s[200005],ss[200005],sss;
map<string,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n>0){
		for(int k=1;k<=n;k++){
			cin>>s[k]>>ss[k];
			for(int i=0;i<s[k].size();i++){
				if(s[k][i]!=ss[k][i]){
					st=i;
					break;
				}
			}
			for(int i=s[k].size()-1;i>=0;i--){
				if(s[k][i]!=ss[k][i]){
					t=i;
					break;
				}
			}
			if(ss[k]<s[k]){
				sss=ss[k];
				ss[k]=s[k];
				s[k]=sss;
			}
			int si=0;
			sss="";
			for(int i=st;i<=t;i++){
				sss+="0";
				sss[si]=s[k][i];
				si++;
				sss+="0";
				sss[si]=ss[k][i];
				si++;
			}

			if(mp[sss]){
				
			}else{
				mpi++;
				mp[sss]=mpi;
			}
			ai[mp[sss]]++;
			a[mp[sss]].push_back(k);
		}
		int k=n+1;
		for(int ii=1;ii<=q;ii++){
			int ans=0;
			cin>>s[k]>>ss[k];
			for(int i=0;i<s[k].size();i++){
				if(s[k][i]!=ss[k][i]){
					st=i;
					break;
				}
			}
			for(int i=s[k].size()-1;i>=0;i--){
				if(s[k][i]!=ss[k][i]){
					t=i;
					break;
				}
			}
			if(ss[k]<s[k]){
				sss=ss[k];
				ss[k]=s[k];
				s[k]=sss;
			}
			sss="";
			int si=0;
			for(int i=st;i<=t;i++){
				sss+="0";
				sss[si]=s[k][i];
				si++;
				sss+="0";
				sss[si]=ss[k][i];
				si++;
			}
			int m=ai[mp[sss]];
			for(int i=0;i<m;i++){
				if((int)s[k].find(s[a[mp[sss]][i]])!=-1&&(int)ss[k].find(ss[a[mp[sss]][i]])!=-1){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}	
	}
	return 0;
}
