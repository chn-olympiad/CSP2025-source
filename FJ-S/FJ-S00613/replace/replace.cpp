#include <iostream>
#include <cstring>
using namespace std;

string s[2][200005];
long long ans=0;
int n,q;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[0][i]>>s[1][i];
	}
	while(q--) {
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		bool b=true;
		for(int i=0; i<t1.size(); i++) {
			for(int j=1; j<=n; j++) {
				for(int v=0,k=i; v<s[0][j].size(); v++,k++) {
					if(s[0][j][v]!=t1[k]&&k==t1.size()) {
						b=false;
						break;
					}
				}
				if(b) {
					for(int v=0,k=i; v<s[0][j].size(); v++,k++) {
						t1[k]=s[1][j][v];
					}
					b=true;
					for(int v=0; v<t1.size(); v++) {
						if(t1[v]!=t2[v]) {
							b=false;
							break;
						}
					}
					if(b) {
						ans++;
					}
					for(int v=0,k=i; v<s[0][j].size(); v++,k++) {
						t1[i]=s[0][j][v];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
