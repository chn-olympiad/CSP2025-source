#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005][3],s,f;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(q--){
		cin>>s>>f;
		int o=-1,p=s.size()-1,ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!=f[i]&&o==-1){
				o=i;
			}else if(s[i]==f[i]&&o!=-1){
				p=i-1;
			}
		}
		string g=s.substr(o,p-o+1),h=f.substr(o,p-o+1);
		for(int i=1;i<=n;i++){
			if(a[i][1].size()<g.size()){
				continue;
			}else{
				for(int j=0;j<a[i][1].size()-p+o-1;j++){
					string e=a[i][1].substr(j,p-o+1),r=a[i][2].substr(j,p-o+1);
					if(g==e&&f==r){
						ans+=1;
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
} 
//4 2 xabcx xadex ab cd bc de aa bb xabcx xadex aaaa bbbb
//3 4 a b b c c d aa bb aa b a c b a
