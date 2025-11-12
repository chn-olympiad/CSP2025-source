#include<bits/stdc++.h>
#define int long long
#define INF 1e16
using namespace std;
const int N=2e5+10;
string s1[N],s2[N],t1,t2;
int len[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len1=t1.length(),len2=t2.length();
		if(len1!=len2){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=0;k<len[j];k++){
				for(int t=0;t<len1;t++){
					if(t1[t]==s1[j][k]&&t2[t]==s2[j][k]&&t+len[j]<=len1){
						bool ff=1;
						for(int tt=1;tt<len[j];tt++){
							if(t1[t+tt]!=s1[j][k+tt]||t2[t+tt]!=s2[j][k+tt]){
								ff=0;
								break;
							}
						}
						if(ff){
							ans++;
							break;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
