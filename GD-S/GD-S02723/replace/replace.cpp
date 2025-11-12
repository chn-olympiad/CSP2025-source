#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+5,mod=1e9+7;
int n,q,ans,cnt,l,pos1,pos2,p1,p2;
bool flag;
string s[N][2],t[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++){ans=0;
		if(t[i][0].size()!=t[i][1].size()){
			cout<<"0\n";continue;
		}
		for(int j=0;j<t[i][0].size();j++)
			if(t[i][0][j]!=t[i][1][j]){
				pos1=j;break;
			}
		for(int j=t[i][0].size()-1;;j--)
			if(t[i][0][j]!=t[i][1][j]){
				pos2=j;break;
			}
		for(int j=1;j<=n;j++){
			for(int k=0;k<s[j][0].size();k++)
				if(s[j][0][k]!=s[j][1][k]){
					p1=k;break;
				}
			for(int k=s[j][0].size()-1;;k--)
				if(s[j][0][k]!=s[j][1][k]){
					p2=k;break;
				}
			if(p1+pos2!=pos1+p2)continue;
			flag=0;
			for(int k=0;k<=p2-p1;k++){
				if(s[j][0][p1+k]!=t[i][0][pos1+k]||s[j][1][p1+k]!=t[i][1][pos1+k]){
					flag=1;break;
				}
			}
			if(!flag)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
