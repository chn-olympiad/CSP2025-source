#include<bits/stdc++.h>
using namespace std;
long long n,q;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
			continue;
		}
		else{
			int l=0;
			int r=s1.size();
			int x=s1.size();
			long long ans=0;
			string sss="";
			while(l<x){
				sss="";
				r=l;
				while(r<x){
					sss="";
					for(int j=l;j<=r;j++){
						sss+=s1[j];
					}
					string ss2="";
					for(int j=l;j<=r;j++){
						ss2+=s2[j];
					}
					if(mp[sss]==ss2){
						bool f=true;
						for(int j=0;j<l;j++){
							if(s1[j]!=s2[j]){
								f=false;
								break;
							}
						}
						if(f){
							for(int j=r+1;j<x;j++){
								if(s1[j]!=s2[j]){
									f=false;
									break;
								}
							}
							if(f){
								ans++;
							}
						}
					}
					r++;
				}
				l++;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
