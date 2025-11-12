#include <iostream>
#include <cstring>
using namespace std;
int n,q;
string s[110][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for (int i=1;i<=n;i++){
			for (int j=0;j<t1.size();j++){
				if (j+s[i][1].size()-1>t1.size()){
					break;
				}
				int b=1;
				for (int p=0,q=j;p<s[i][1].size();p++,q++){
					if (s[i][1][p]!=t1[q] or s[i][2][p]!=t2[q]){
						b=0;
						break;
					}
				}
				if (b){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
