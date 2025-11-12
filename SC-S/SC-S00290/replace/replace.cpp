#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=10009;
string s[N][2];
string get(int l,int r,string&s){
	string t="";
	for(int i=l;i<=r;i++)t+=s[i];
	return t;
}
map<string,string>mp;
bool ok[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[s[i][1]]=s[i][2];
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int r=0;r<a.size();r++){
			ok[r]=get(r+1,a.size()-1,a)==get(r+1,a.size()-1,b);
		}
		for(int l=0;l<a.size();l++){
			if(get(0,l-1,a)!=get(0,l-1,b))continue;
			for(int r=l;r<a.size();r++){
				if(!ok[r])continue;
				if(mp[get(l,r,a)]==get(l,r,b))
					++ans;
			}
		}
		printf("%d\n",ans);
	}
}