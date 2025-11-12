#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[105][3],s2[105][3],ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i][1]>>s1[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>s2[i][1]>>s2[i][2];
		for(int j=1;j<=n;j++){
			if(s1[j][1]==s2[i][1]&&s1[j][2]==s2[i][2]) ans++;
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
