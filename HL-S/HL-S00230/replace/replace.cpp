#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=0;i<q;i++){
		string t[5];
		string a1,a2;
		int ans=0;
		cin>>t[1]>>t[2];
		for(int j=0;j<t[1].size();j++){
			if(t[1][j]==t[2][j]){
				continue;
			}else{
				a1+=t[1][j];
				a2+=t[2][j];
			}
		}
		for(int j=0;j<n;j++){
			if((a1==s[j][1]&&a2==s[j][2])||(t[1]==s[j][1]&&t[2]==s[j][2])){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
