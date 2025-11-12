#include <bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int n,m;
string s[N][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n>>m;
	for(int i=0;i<n;i++)cin >>s[i][0]>>s[i][1];
	while(m--){
		int ans=0;
		cin >>t[0]>>t[1];
		for(int i=0;i<n;i++){
			if(s[i][0].size()>t[0].size())continue;
			for(int j=0;j<t[0].size();j++){
				bool o=0;
				string str=t[0];
				for(int k=0;k<s[i][0].size();k++)
					if(j+k>=str.size()||str[j+k]!=s[i][0][k]){o=1;break;}
					else str[j+k]=s[i][1][k];
				if(!o){
					if(str==t[1])ans++;
				}
			}
		}
		cout <<ans<<"\n";
	}
	return 0;
}
