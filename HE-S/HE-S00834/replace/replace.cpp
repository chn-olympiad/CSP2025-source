#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
const int MAXN=2e5+5;
string s1[MAXN],s2[MAXN];

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	for(int i=1; i<=q; i++) {
		int ans=0;
		string s,c;
		cin>>s>>c;
		int len=s.length();
		for(int j=1; j<=n; j++) {
			int chang=s1[j].length();
			for(int k=0; k<len; k++) {
				int flag=0;
				for(int p=k;p<=chang+k;p++){
					if(s[p]==s1[j][p-k]) flag++;
				}
				if(flag==chang){
					flag=0;
					for(int p=k;p<=chang+k;p++){
						if(c[p]==s2[j][p-k]) flag++;
					}
					if(flag==chang) ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
