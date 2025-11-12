#include<bits/stdc++.h>
using namespace std;
#define ll long long
void st(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int nm=5005;
int n,m,k,ans,cnt,q,flag;
string s[nm][3],t[3];
bool ifok(int id){
	for(int i=0;i<t[1].length();i++){
		int pos=0,len=s[id][1].length();
		while(s[id][1][pos]==t[1][i+pos]){
			pos++;
			if(pos==len) break;
		}
		if(pos==len){
			pos=0;
			int lenb=s[id][2].length();
			for(int j=i;j<=i+lenb-1;j++){
				if(s[id][2][pos]!=t[2][j]) break;
				pos++;
				if(pos==lenb){
					int lenc=t[2].length();
					if(j==lenc-1) return 1;
					for(int k=j+1;k<lenc;k++){
						if(t[1][k]!=t[2][k]) break;
						if(k==lenc-1) return 1;
					}
				}
			}
			return 0;
		}
		if(t[1][i]!=t[2][i]) return 0;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	st();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t[1]>>t[2];
		if(t[1].length()!=t[2].length()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(ifok(i)){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
