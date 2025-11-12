#include <bits/stdc++.h>
//#define int long long
//#define db double
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> s1[i] >> s2[i];
	while(q--){
		cin >> t1 >> t2;
		int l=t1.size(),L=0,R=0,ans=0;
		for(int i=0;i<l;i++){
			if(t1[i]!=t2[i]){
				if(!L) L=i,R=i;
				else R=i;
			}
		}
		for(int i=1;i<=n;i++){
			int l2=s1[i].size();
			if(l2<R-L+1) continue;
			for(int j=0;j<l;j++){
				int flag=1;
				if(j+l2-1>=l) break;
				for(int k=0;k<l2;k++){
					if(s1[i][k]!=t1[j+k] || s2[i][k]!=t2[j+k]){
						flag=0;
						break;
					}
				}
				if(flag && j<=L && R<=j+l2+1){
					ans++;
					break;
				}
			}
		}
		cout << ans <<"\n";
	}
	return 0;
}
