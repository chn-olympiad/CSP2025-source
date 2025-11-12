#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

string t[N][2];
map <string,string> mapp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n,q;
	cin >> n >> q;
	for (int i=1;i<=n;i++) {
		string s1,s2;
		cin >> s1 >> s2;
		mapp[s1]=s2;
	}
	while (q--) {
		int ans=0;
		string s1,s2;
		cin >> s1 >> s2;
		int st=0,ed=s1.size();
		for (int i=0;i<s1.size();i++) {
			if (s1[i]==s2[i]) st=i;
			else break;
		}
		for (int i=s1.size()-1;i>st;i--) {
			if (s1[i]==s2[i]) ed=i;
			else break;
		}
		for (int i=0;i<=st;i++) {
			for (int j=s1.size();j>=ed;j--) {
				string r1="",r2="";
				for (int x=(i?i+1:0);x<=j-1;x++) {
					r1+=s1[x];
					r2+=s2[x];
				}
				if (mapp[r1]==r2) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
