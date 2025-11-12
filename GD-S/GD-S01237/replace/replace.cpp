#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2005,M=13331;
int n,q,ans=0;
string ss[N][3];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>ss[i][1]>>ss[i][2];
		ss[i][1]=" "+ss[i][1];
		ss[i][2]=" "+ss[i][2];
	}
	string s1,s2;
	while(q--) {
		ans=0;
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		for(int i=1; i<=n; i++) {
			int nn=ss[i][1].size()-1;
			for(int j=1; j+nn-1<=int(s1.size()); j++) {
				int a1=1,a2=j-1;
				int b1=j,b2=j+nn-1;
				int c1=j+nn,c2=s1.size()-1;
				bool bb=true;
				for(int ii=a1; ii<=a2; ii++) {
					if(s1[ii]!=s2[ii]) {
						bb=false;
					}
				}
				for(int ii=b1; ii<=b2; ii++) {
					if(s1[ii]!=ss[i][1][ii]) {
						bb=false;
					}
				}
				for(int ii=b1; ii<=b2; ii++) {
					if(s2[ii]!=ss[i][2][ii]) {
						bb=false;
					}
				}
				for(int ii=c1; ii<=c2; ii++) {
					if(s1[ii]!=s2[ii]) {
						bb=false;
					}
				}
				if(bb) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
