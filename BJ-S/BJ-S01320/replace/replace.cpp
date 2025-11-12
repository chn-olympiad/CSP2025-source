#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,cnt;
string s[N][2],st,t;
void dfs(string x){
	cout<<x<<'\n';
	if(x==t){
		cnt++;
		return ;
	}
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>st>>t;
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i][0].size()-1<st.size();j++){
				string sub=st.substr(j,s[i][0].size());
				if(sub==s[i][0]){
					string it=st.substr(0,j)+s[i][1]+st.substr(j+s[i][0].size());
					if(it==t) cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex  
*/
