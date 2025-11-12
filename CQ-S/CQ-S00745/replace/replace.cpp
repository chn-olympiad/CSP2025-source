#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200010][3];
string t[200010][3];
int ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int j=1;j<=m;j++) cin>>t[j][1]>>t[j][2];
	for(int i=1;i<=m;i++){
		if(t[i][1].size()!=t[i][2].size()){
			cout<<0<<endl;
			continue;
		}
		ans=0;
		string v[3][10010];
		int o1=0,o2=0;
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]!=t[i][2][j]&&j==0){
				string k1;k1+=t[i][1][j];
				string k2;k2+=t[i][2][j];
				v[1][++o1]=k1;
				v[2][++o2]=k2;
			}else if(t[i][1][j]!=t[i][2][j]&&t[i][1][j-1]==t[i][2][j-1]){
				string k1;k1+=t[i][1][j];
				string k2;k2+=t[i][2][j];
				v[1][++o1]=k1;
				v[2][++o2]=k2;
			}else if(t[i][1][j]!=t[i][2][j]&&t[i][1][j-1]!=t[i][2][j-1]){
				string ss1=v[1][o1];
				string ss2=v[2][o2];
				v[1][o1]=string(ss1+t[i][1][j]);
				v[2][o2]=string(ss2+t[i][2][j]);
			}
		}
		for(int j=1;j<=n;j++){
			int h=0;
			for(int k=1;k<=o1;k++){
				for(int l=0;l<s[j][1].size();l++){
					string c1=v[1][k];
					string c2=v[2][k];
					if(s[j][1][l]==c1[0]&&s[j][2][l]==c2[0]&&c1.size()<=s[j][1].size()){
						bool f=1;
						for(int r=1;r<=o1;r++){
							if(s[j][1][l+r]!=c1[r]||s[j][2][l+r]!=c2[r]){
								f=0;
								break;
							}
						}
						if(f){h++;break;}
					}
				}
			}
			if(h==o1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
