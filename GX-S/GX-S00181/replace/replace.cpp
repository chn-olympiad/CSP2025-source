#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string t[4],s[200005][4],t1;
const string u="xadex",v="cd";
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin >> t[1] >> t[2];
		if(t[1].size() != t[2].size()){
			cout << "0\n";
			continue;
		} ans=0;
		for(int j=1;j<=n;j++){
			t1=t[1];
			if(int(t1.find(s[j][1])) == int(t[2].find(s[j][2])) and int(t1.find(s[j][1])>=0)){
				for(unsigned int k=t[1].find(s[j][1]);k<t[1].find(s[j][1])+s[j][1].size();k++){
					t1[k] = s[j][2][k-t[1].find(s[j][1])];
				} if(t1==t[2])ans++;
				//cout << "# " << int(t[1].find(s[j][1])) << " # " << int(t[2].find(s[j][2])) << " # " << s[j][2] << " ** ";
			}
		}
		cout << ans << "\n";
	}
}
//40
