#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][3],t[3];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	if(q*n>1e6) {
		for(int i=1;i<=q;i++) {
			cin>>t[1]>>t[2];
			cout<<0<<endl;
		}
		return 0;
	}
	while(q--) {
		cin>>t[1]>>t[2];
		if(t[1].size()!=t[2].size()) {
			cout<<0<<endl; 
			continue;
		} 
		int len=t[1].size(),cnt=0;
		for(int i=0;i<len;i++) {
			int pd=0;
			for(int j=0;j<i;j++) {
				if(t[1][j]!=t[2][j]) {
					pd=1;
					break;
				}
			}
			if(pd) continue;
			for(int j=1;j<=n;j++) {
				int l=s[j][1].size(),flag=0;
				if(i+l-1>=len) continue;
				for(int k=0;k<l;k++) {
					if(t[1][i+k]!=s[j][1][k]||t[2][i+k]!=s[j][2][k]) {
						flag=1;
						break;
					}
				}
				for(int k=i+l;k<len;k++) {
					if(t[1][k]!=t[2][k]) {
						flag=1;
						break;
					}
				}
				if(!flag) cnt++; 
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
