#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[20000][2],t[20000][2];
string x,y,z,x1,y1,z1;
int ans=0;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[i][1]>>s[i][2];
	}
	for(int qq=1; qq<=q; qq++) {
		cin>>t[qq][1]>>t[qq][2];
		ans=0;
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				for(int k=0; k<=n; k++) {
					x=s[i][1];x1=s[i][2];
					y=s[j][1];y1=s[j][2];
					z=s[k][1];z1=s[k][2];
					if(x+y+z==t[qq][1]){
						if(x+y+z==t[qq][2]) ans++;
						else if(x1+y1+z1==t[qq][2])ans++;
						else if(x1+y1+z==t[qq][2])ans++;
						else if(x1+y+z1==t[qq][2])ans++;
						else if(x1+y+z==t[qq][2])ans++;
						else if(x+y1+z==t[qq][2])ans++;
						else if(x+y1+z1==t[qq][2])ans++;
						else if(x+y+z1==t[qq][2])ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
