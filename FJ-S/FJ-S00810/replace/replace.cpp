#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
char s1[200005][2005],s2[200005][2005],t1[20005],t2[20005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		ans=0;
		cin>>t1>>t2;
		int l=0,r=strlen(t1);
		for(; t1[l]==t2[l]; l++);
		for(; t1[r]==t2[r]; r--);
		for(int i=0; i<n; i++) {
			if(strlen(s1[i])<r-l+1) {
				continue;
			}
			for(int j=0; j<strlen(t1)-strlen(s1[i])+1; j++) {
				if(t1[j]==s1[i][0]&&t2[j]==s2[i][0]&&j<=l&&j+strlen(s1[i])>r) {
					bool flg=true;
					for(int k=0; k<strlen(s1[i]); k++) {
						if(t1[j+k]!=s1[i][k]||t2[j+k]!=s2[i][k]) {
							flg=false;
							break;
						}
					}
					if(flg) {
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
