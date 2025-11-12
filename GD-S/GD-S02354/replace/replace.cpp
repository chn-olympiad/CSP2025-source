#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
vector<string>v[200010];
vector<int>vlen;
map<int,bool>mplen;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int now=0;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		int len=a.size();
		if(!mplen[len]){
			mplen[len]=1;
			vlen.push_back(len);
		}
		if(mp[a]==0){
			now++;
			mp[a]=now;
			v[now].push_back(b);
		}else{
			v[mp[a]].push_back(b);
		}
	}
	for(int i=0;i<m;i++){
		string a,b;
		cin>>a>>b;
		int res=0;
		for(auto x:vlen){
			for(int j=0;j<a.size()-x+1;j++){
				string tmp=a.substr(j,x);
				if(mp[tmp]){
					for(auto str:v[mp[tmp]]){
						string s1,s2;
						s1=a.substr(0,j);
						s2=a.substr(j+x,max(0,int(a.size()-str.size()-j-x)));
						if(s1+str+s2==b){
							res++;
						}
					}
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
