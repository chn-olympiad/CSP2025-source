#include<bits/stdc++.h> 
using namespace std;
int n,q,num=0;
string s[200005][3],t[200005][3];
vector<int>ans[2];
void find(string a,string b,int i){
	for(int j=0;j<a.size()-b.size()+1;j++){
		bool x=1;
		for(int k=0;k<b.size();k++){
			if(a[j+k]!=b[k]){
				x=0;
				break;
			}
		}
		if(x==1)ans[i].push_back(j);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		num=0;
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			find(t[i][1],s[j][1],0);
			find(t[i][2],s[j][2],1);
			for(int i=0;i<ans[0].size();i++){
				for(int j=0;j<ans[1].size();j++){
					if(ans[0][i]==ans[1][j])num++;
				}
			}
			ans[0].clear();
			ans[1].clear();
		}
		cout<<num<<endl;
		
	}
	return 0;
} 
