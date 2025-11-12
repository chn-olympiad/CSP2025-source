#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
map<string,int> z;
string ss[10010][110];
int sz[10010];
string a,aa;
int cnt=0;
void dfs(string s){
	if(s==aa){
		cnt++; 
	} 
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			string sa;
			for(int k=i;k<=j;k++){
				sa+=s[k];
			}
			//cout<<sa<<endl;
			if(z.count(sa)){
				//cout<<sa<<" ";
				for(int l=1;l<=sz[z[sa]];l++){
					string saa=s;
					for(int k=i;k<=j;k++){																																																																																									
						saa[k]=ss[z[sa]][l][k-i];
					}
					dfs(saa);
				}
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q,zs=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){ 
		string s_1,s_2;
		cin>>s_1>>s_2;
		if(!z.count(s_1)){
			zs++;
			z[s_1]=zs;
		}
		sz[z[s_1]]++;
		ss[z[s_1]][sz[z[s_1]]]=s_2;
	}
	while(q--){
		cnt=0;
		cin>>a>>aa;
		dfs(a);
		cout<<cnt<<endl;
	}
	return 0;
} 