#include <bits/stdc++.h>
using namespace std;
const int maxn=10020;
int n,q;
string s[maxn][2];
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	string s1,s2;
	int ans=0;
	while(q--){
		ans=0;
		cin>>s1>>s2;
		if((int)s1.size()!=(int)s2.size()){
			cout<<0<<endl;
			continue;
		}
		int l=1,r=1;
		for(int i=1;i<(int)s1.size();i++){
			if(l==i&&s1[i]==s2[i]){
				l=r=i;
				continue;
			}
			if(s1[i]!=s2[i])
				r++;
		}
		int k=0;
		for(int i=1;i<=n;i++){
			if(r-l+1>(int)s[i][0].size())continue;
			if(s1==s[i][0]&&s2==s[i][1])ans++;
			k=0;
			for(int j=1;j<(int)s[i][0].size();j++){
				if(k==0&&s[i][0][j]!=s1[l])continue;
				for(k=0;k+l<=r;k++){
					if(s1[l+k]!=s[i][0][j+k]||s2[l+k]!=s[i][1][j+k]){
						k=0;
						break;
					}
				}
				if(k!=0){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
