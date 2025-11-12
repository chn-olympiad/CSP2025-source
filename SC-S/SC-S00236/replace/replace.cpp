#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t[200005][3];
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][1]>>t[i][2];
		for(int l=0;l<=t[i][1].size();l++){
			string ss="";
			for(int r=l+1;r<=t[i][1].size()+1;r++){
				ss+=t[i][1][r-1];
				for(int j=1;j<=n;j++){
					if(ss==s[j][1]){
						string s1="";
						for(int k=0;k<l;k++)s1+=t[i][1][k];
						for(int k=0;k<r-l;k++)s1+=s[j][2][k];
						for(int k=r;k<t[i][1].size();k++)s1+=t[i][1][k];
						if(s1==t[i][2])ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}