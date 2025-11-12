#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
#define PII pair<int,int>
#define tp tuple<int,int,int>
#define fi(x) (x.first)
#define se(x) (x.second)
int n,m;
string s1[200005],s2[200005],s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	I n >> m;
	for(int i=1;i<=n;i++) I s1[i] >> s2[i];
	for(int i=1;i<=m;i++){
		I s >> t;
		if(s.length()!=t.length()){
			O "0\n";
			continue;
		}
		queue<string> q;
		q.push(s);
		int siz=s.length(),res=0;
		while(!q.empty()){
			string f=q.front();
			q.pop();
			if(f==t){
				res++;
				continue;
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<siz;j++){
					string str="";
					for(int k=j;k<j+s1[i].length()&&k<siz;k++) str+=f[k];
					if(str==s1[i]){
						string st="";
						for(int k=0;k<j;k++) st+=f[k];
						st+=s2[i];
						for(int k=j+s1[i].length();k<s.length();k++) st+=f[k];
						q.push(st);
					} 
				}
			}
		}
		O res << "\n";
	}
	return 0;
}
