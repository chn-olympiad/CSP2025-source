#include<iostream>
#include<cstdio>
using namespace std;
int k,t;
pair<string,string>mp[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>k>>t;
	for(int i=0;i<k;i++){
		string x,y;
		cin>>x>>y;
		mp[i].first=x;
		mp[i].second=y;
	}
	while(t--){
		int ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=0;i<k;i++){
			string s1,s2;
			s1=mp[i].first;
			s2=mp[i].second;
			for(int j=0;j<x.size();j++){
				if(x[j]==s1[0]||x[j]==s2[0]){
					int flag=0;
					for(int l=0;l<s1.size();l++){
						if(s1[l]==x[j+l]){
							flag++;
						}
					}
					if(flag==s1.size()){
						string sx="",sz="";
						for(int l=0;l<j;l++){
							sx=sx+x[l];
						}
						for(int l=j+s1.size();l<x.size();l++){
							sz=sz+x[l];
						}
						string news=sx+s2+sz;
						if(news==y){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
