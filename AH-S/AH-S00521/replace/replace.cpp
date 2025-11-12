#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		int res=0;
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				if(t1.size()-i<s[j][0].size()) continue;
				bool f=1;
				for(int k=0;k<s[j][0].size();k++){
					if(s[j][0][k]!=t1[i+k]){
						f=0;
						break;
					}
				}
				if(f){
					string t;
					for(int k=0;k<i;k++){
						t+=t1[k];
					}
					for(int k=0;k<s[j][1].size();k++){
						t+=s[j][1][k];
					}
					for(int k=i+s[j][0].size();k<t1.size();k++){
						t+=t1[k];
					}
					if(t==t2) res++;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
