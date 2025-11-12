#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string t[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
		if(t[i][1].size()!=t[i][2].size()){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(t[i][1].size()<s[j][1].size()){
				continue;
			}
			for(int k=0;k<=t[i][1].size()-s[j][1].size();k++){
				int fl=1;
				for(int l=0;l<s[j][1].size();l++){
					if(t[i][1][k+l]!=s[j][1][l]){
						fl=0;
						break;
					}
					if(t[i][2][k+l]!=s[j][2][l]){
						fl=0;
						break;
					}
					if(l==0&&k>0){
						if(t[i][1][k+l-1]!=t[i][2][k+l-1]){
							fl=0;
							break;
						}
					}
					if(l==s[j][1].size()-1){
						if(t[i][1][k+l+1]!=t[i][2][k+l+1]){
							fl=0;
							break;
						}
					}
				}
				if(fl){
					cnt++;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

