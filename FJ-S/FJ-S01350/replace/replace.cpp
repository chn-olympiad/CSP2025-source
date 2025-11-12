#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int len=s[i][0].size();
		for(int j=0;j<len;j++){
			if(s[i][0][j]!=s[i][1][j]){
				s[i][0]=s[i][0].substr(j);
				s[i][1]=s[i][1].substr(j);
				break;
			}
		}
		len=s[i][0].size();
		for(int j=len-1;j>=0;j--){
			if(s[i][0][j]!=s[i][1][j]){
				s[i][0]=s[i][0].substr(0,j+1);
				s[i][1]=s[i][1].substr(0,j+1);
				break;
			}
		}
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int len=t1.size();
		for(int j=0;j<len;j++){
			if(t1[j]!=t2[j]){
				t1=t1.substr(j);
				t2=t2.substr(j);
				break;
			}
		}
		len=t1.size();
		for(int j=len-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				t1=t1.substr(0,j+1);
				t2=t2.substr(0,j+1);
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i][0]==t1 && s[i][1]==t2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
