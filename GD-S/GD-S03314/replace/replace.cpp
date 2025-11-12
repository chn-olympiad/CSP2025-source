#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][5],t[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	for(int i=1;i<=q;i++){
		int ans=0,t1=t[i][1].size();
		for(int j=1;j<=n;j++){
			int s1=s[j][1].size();
			for(int k=0;k<=t1-s1;k++){
				string y,yy;
				for(int l=0;l<s1;l++){
					y+=t[i][1][k+l];
					yy+=t[i][2][k+l];
				}
				if(y==s[j][1]&&yy==s[j][2]){
					string x,xx,z,zz;
					for(int l=0;l<k;l++){
						x+=t[i][1][l];
						xx+=t[i][2][l];
					}
					for(int l=s1+k;l<t1;l++){
						z+=t[i][1][l];
						zz+=t[i][2][l];
					}
					if(x==xx&&z==zz)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
