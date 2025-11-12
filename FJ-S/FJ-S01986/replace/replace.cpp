#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][5],x,y,tmp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			for(int k=0;k<x.size();k++){
				if(x[k]==s[j][1][0]){
					bool can=1;
					tmp=x;
					for(int l=1;l<s[j][1].size();l++){
						if(x[k+l]!=s[j][1][l]){
							can=0;
							break;
						}
						tmp[k+l]=s[j][2][l];
					}
					if(can&&tmp==y) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
