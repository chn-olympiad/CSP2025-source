#include<bits/stdc++.h>
using namespace std;
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i][0].size()-1<x.size();j++){
				bool v=true;
				for(int k=0;k<x.size();k++){
					if(k<j||k>=j+s[i][0].size()){
						if(x[k]!=y[k]){
							v=false;
							break;
						}
					}else{
						if(s[i][0][k-j]!=x[k]||s[i][1][k-j]!=y[k]){
							v=false;
							break;
						}
					}
				}
				if(v)++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
