#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=2*m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=2*m;i+=2){
		long long ans=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]==s[i+1][j]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
