#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s[1000001][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t[1]>>t[2];
		int len=t[1].size()-1;
		for(int i=1;i<=len-2;i++){
			for(int j=i+1;j<=len-1;j++){
				for(int k=j+1;k<=len;k++){
					string y;
					for(int l=j;l<k;l++){
						y+=t[l];
					}
					for(int l=1;l<=n;l++){
						if(y==s[l][1]){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}