#include <iostream>
#include <string>
using namespace std;
const int MAXN=2e5+10;
string db[MAXN][2];
int n,q;
int main() {
	// i want to play delta force!!!
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=0;i<n;i++) {
		cin>>db[i][0]>>db[i][1];
	}
	string a,b;
	while (q--) {
		cin>>a>>b;
		int asw=0;
		for (int i=0;i<n;i++) {
			auto p=a.find(db[i][0]);
			//cout<<"trying "<<i<<endl;
			//cout<<"found at "<<p<<endl;
			if (p>a.length()) continue;
            string tmp=a;
            int dead=db[i][0].length();
            for (int j=0;j<dead;j++) {
                tmp[p+j]=db[i][1][j];
            }
            //cout<<"result:"<<tmp<<endl;
            if (tmp==b) {
				//cout<<"try "<<i<<" successfully\n";
				asw++;
			}
		}
		cout<<asw<<endl;
	}
    return 0;
}
