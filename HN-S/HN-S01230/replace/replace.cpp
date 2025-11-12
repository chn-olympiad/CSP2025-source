#include<bits/stdc++.h>
using namespace std;
const int kMaxN=2e5+5,kMaxL=5e6+5;
int n,q,ans;
string s[kMaxN][4],t[kMaxN][4];
void S1(){
	for(int i=1;i<=q;i++){
		ans=0;
		int sx=-1,ex=t[i][1].size();
		for(int j=0;j<t[i][1].size();j++){
			if(t[i][1][j]!=t[i][2][j]) break;
			sx=j;
		}
		for(int j=t[i][1].size()-1;j>=0;j--){
			if(t[i][1][j]!=t[i][2][j]) break;
			ex=j;
		}
		for(int x=1;x<=n;x++){
			for(int j=0;j+s[x][1].size()-1<t[i][1].size();j++){
				bool F=0;
				int r=j+s[x][1].size()-1;
				if(!(j<=sx+1&&r>=ex-1)) continue;
				for(int k=j,p=0;k<=r;k++,p++){
					if(s[x][1][p]!=t[i][1][k]||s[x][2][p]!=t[i][2][k]){
						F=1;
						break;
					}
				}
				if(!F&&j<=sx+1&&r>=ex-1){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	S1();
    return 0;
}

