#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][2],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			int p=t1.find(s[i][0]);
			if(p!=-1){
				string t=t1.substr(0,p)+s[i][1]+t1.substr(p+s[i][1].size());
				//cout<<t<<endl;
				if(t==t2)cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
