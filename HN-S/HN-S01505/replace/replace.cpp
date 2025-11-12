#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<bits/stl_pair.h>
#define N 200005
using std::string;
using std::cout;
using std::cin;
using std::pair;
pair<string,string> s[N];
int n,q,ans;
void read() {
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s[i].first>>s[i].second;
}
void solve() {
	for(int i=1; i<=q; i++) {
		string t1,t2;
		ans=0;
		cin>>t1>>t2;
		for(int j=0; j<t1.length(); j++) {
			string tt=t1;
			for(int k=1; k<=n; k++)
				if(tt[j]==s[k].first[0]) {
					bool flag=true;
					string skf=s[k].first,sks=s[k].second;
					for(int l=0; l+j<tt.length()&&l<skf.length(); l++)
						if(tt[l+j]==skf[l])
							tt[l+j]=sks[l];
						else {
							flag=false;
							break;
						}
					if(flag) {
						if(tt==t2)
							ans++;
					}
					tt=t1;
				}
		}
		cout<<ans<<'\n';
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read();
	solve();
	return 0;
}
