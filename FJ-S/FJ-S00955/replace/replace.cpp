#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2],t[200005][2],ts[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][0]>>t[i][1];
		int asd=t[i][0].size();
		for(int j=1;j<asd;j++){
			ts[j]=ts[j-1]+t[j][0];
		}
		for(int j=1;j<=n;j++){
			if((s[j][0]==t[i][0]&&s[j][1]==t[j][1])){
				ans++;
			}
		}cout<<ans;
	}
	
}
