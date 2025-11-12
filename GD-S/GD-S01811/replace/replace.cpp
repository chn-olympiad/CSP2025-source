#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int inf = 0x3f3f3f3f;
int n,q,flg,ans;
string s[N][2],t[N][2];
int aa,bb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k+s[j][0].length()-1<t[i][0].length();k++){
				flg=0;
				for(int x=k;x<k+s[j][0].length();x++){
					
					if(s[j][0][x-k]!=t[i][0][x]){
						flg=1;
					}
					swap(t[i][0][x],s[j][1][x-k]);
				}
				for(int x=0;x<t[i][0].length();x++){
					if(t[i][0][x]!=t[i][1][x])flg=1;
				}
				for(int x=k;x<k+s[j][0].length();x++){
					
					swap(t[i][0][x],s[j][1][x-k]);
				}
				if(flg)continue;
				ans++;
				//cout<<t[i][0]<<' '<<s[j][0]<<'\n';
			}
		}cout<<ans<<'\n';
	}
	
	
	
	
	return 0;
}
