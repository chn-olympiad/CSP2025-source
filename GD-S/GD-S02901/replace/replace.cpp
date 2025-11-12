#include<bits/stdc++.h>
#define I using 
#define AK namespace
#define CSP std
I AK CSP ;
const int maxn=2e5+5;
int n,q;
string s[maxn][5];
int main () {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	while (q--) {
		int cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		for (int i=1;i<=n;i++) {
			int pos=t1.find(s[i][1]);
			//cout<<(t1.find(s[i][1])>t1.size())<<"\n";
			if (t1.find(s[i][1])>t1.size()) continue;
			string x="",z="";
			for (int j=0;j<pos;j++) {
				//cout<<"!\n";
				x+=t1[j];
			}
			for (int j=pos+s[i][1].size();j<t1.size();j++) {
				z+=t1[j];
			}
			string tmp=x+s[i][2]+z;
			//cout<<x<<' '<<s[i][2]<<' '<<z<<"\n";
			//cout<<tmp<<"\n";
			if (tmp==t2) {
				cnt++; 
				//cout<<"-------------\n";
				//cout<<tmp<<"\n";
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
1 1
bc de
xabcx xadex
*/
