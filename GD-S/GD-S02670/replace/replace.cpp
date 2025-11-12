#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,q,lens[N],len,tmp[N];
string s[5][N],t[5],a;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		lens[i]=s[0][i].size();
		tmp[i]=-1;
		for (int j=0;j<lens[i];j++){
			if (s[0][i][j]!=s[1][i][j]){
				if (j==tmp[i]+1||tmp[i]==-1){
					tmp[i]=j;s[2][i].push_back(s[0][i][j]);
				} else {
					break ;
				}
			}
		}
	}
	while (q--){
		int ans=0;
		cin>>t[0]>>t[1];t[2]="";
		len=t[0].size();
		int lst=-1;
		for (int j=0;j<len;j++){
			if (t[0][j]!=t[1][j]){
				if (j==lst+1||lst==-1){
					lst=j;t[2].push_back(t[0][j]);
				} else {
					break ;
				}
			}
		}
		for (int i=1;i<=n;i++){
			if (t[2]==s[2][i]){
				if (lst<tmp[i]||lens[i]-tmp[i]>len-lst) continue ;
				a=t[0];int k=lst-tmp[i];
				int fl=1;
				for (int j=0;j<lens[i];j++){
					if (a[j+k]!=s[0][i][j]){
						fl=0;
						continue ;
					}
					a[j+k]=s[1][i][j];
				}
				if (fl==1&&a==t[1]) ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}
