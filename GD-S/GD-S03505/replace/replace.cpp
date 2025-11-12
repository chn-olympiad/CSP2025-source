#include<bits/stdc++.h>
using namespace std;
string s[200005][3],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;++i){
			if(s[i][1].size()>t1.size())continue;
			for(int j=0;j<t1.size()-s[i][1].size()+1;++j){
				bool flag=0;
				for(int k=0;k<s[i][1].size();++k){
					if(s[i][1][k]!=t1[j+k]){
						flag=1;
						break;
					}
				}
				if(!flag){
					string tmp=t1;
					for(int k=0;k<s[i][1].size();++k){
					t1[j+k]=s[i][2][k];
				}
				flag=0;
				for(int k=0;k<t1.size();++k){
					if(t1[k]!=t2[k]){
						flag=1;
						break;
					}
				}
				if(!flag)ans++;
				t1=tmp;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
