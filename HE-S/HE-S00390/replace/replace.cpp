#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxl=1000006;
string s[maxn][2];
string t1,t2;
int next[maxn][maxl];
int n,q;

void get_next(){
	for(int i=0;i<n;++i){
		next[i][0]=-1;
		for(int j=1;j<=s[i][0].length();++j){
			int k=next[i][j-1];
			while(s[i][0][k]!=s[i][0][j-1] && k!=-1){
				k=next[i][k];
			}
			next[i][j]=k+1;
		}
	}
}

int trydo(){
	int ans=0;
	for(int i=0;i<n;++i){
		for(int begin=0,len=0;begin+s[i][0].length()<=t1.length();){
			if(len==s[i][0].length()){
				string tmp=t1;
				for(int j=begin;j<begin+len;++j){
					tmp[j]=s[i][1][j-begin];
				}
//				cout<<tmp<<'\n';
				bool flag=true;
				for(int j=0;j<tmp.length();++j){
					if(tmp[j]!=t2[j]){
						flag=false;
					}
				}
				if(flag){
					++ans;
					break;
				}
				else{
					begin=begin+len;
					len=next[i][len];
					begin=begin-len;
					len=max(0,len);
				}
			}
			if(t1[begin+len]==s[i][0][len]){
				++len;
			}else{
				begin=begin+len;
				len=next[i][len];
				begin=begin-len;
				len=max(0,len);
			}
		}
	} 
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	get_next();
	for(int i=0;i<q;++i){
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<'\n';
		}else cout<<trydo()<<'\n';
	}
}
