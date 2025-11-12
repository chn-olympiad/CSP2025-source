#include<bits/stdc++.h>
using namespace std;
struct str{
	int len;//长度 
	int bpl;//b是第几个 
};
string s[1086][3];
str ss1[200001][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;	
	if(n<=1000){		
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2];
		}
		for(int i=1;i<=m;i++){
			string s1,s2;
			cin>>s1>>s2;
			long long ans=0;
			for(int j=0;j<=s1.length()-1;j++){
				for(int k=1;k<=n;k++){
					bool br=1;
					for(int l=1;l<=s[k][1].length();l++){
						if(j+l>s1.length()){
							br=0;
							break;
						}
						if(s1[j+l-1]!=s[k][1][l-1]||s2[j+l-1]!=s[k][2][l-1]){
							br=0;
							break;
						}		
					}
					for(int l=j+s[k][1].length()+1;l<=s1.length();l++){
						if(s1[l-1]!=s2[l-1]){
							br=0;
							break;
						}
					}
					if(br){
						ans++;
					}
				}
				if(s1[j]!=s2[j]) break;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		string d1,d2;
		cin>>d1>>d2;
		ss1[i][1].len=d1.length();
		ss1[i][2].len=d2.length();
		for(int j=1;j<=d1.length();j++){
			if(d1[j-1]=='b'){
				ss1[i][1].bpl=j;
			}
			if(d2[j-1]=='b'){
				ss1[i][2].bpl=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		str ss2,ss3;
		string d3,d4;
		cin>>d3>>d4;
		ss2.len=d3.length();
		ss3.len=d4.length();
		for(int j=1;j<=d3.length();j++){
			if(d3[j-1]=='b'){
				ss2.bpl=j;
			}
			if(d4[j-1]=='b'){
				ss3.bpl=j;
			}
		}
		long long ans=0;
		for(int j=1;j<=n;j++){
			//cout<<ss1[j][1].len<<" "<<ss1[j][1].bpl<<" "<<ss1[j][2].len<<" "<<ss1[j][2].bpl<<endl;
			if(ss3.bpl-ss2.bpl==ss1[j][2].bpl-ss1[j][1].bpl){
				if(ss2.bpl-1>=ss1[j][1].bpl-1&&ss2.len-ss2.bpl>=ss1[j][1].len-ss1[j][1].bpl){
					if(ss3.bpl-1>=ss1[j][2].bpl-1&&ss3.len-ss3.bpl>=ss1[j][2].len-ss1[j][2].bpl){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
