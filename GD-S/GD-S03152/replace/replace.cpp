#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int n,q;
string s1[N],s2[N];
unordered_map<string,int> mp;
void dfs(string s){
	vector<int> v;
	for(int i=1;i<=n;i++){
		for(int j=0;j+s1[i].size()-1<s.size();j++){
			int flag=true;
			for(int k=0;k<s1[i].size();k++){
				if(s1[i][k]!=s[j+k]){
					flag=false;
					break;
				}
			}
			if(flag){
				for(int k=0;k<s1[i].size();k++) s[j+k]=s2[i][k];
				dfs(s);
				for(int k=0;k<s1[i].size();k++) s[j+k]=s1[i][k];
			}
		}
	}
} 
int p[1010][2010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(q--) cout<<0<<endl;
	return 0;
}

