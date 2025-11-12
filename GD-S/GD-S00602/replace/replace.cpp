#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][3],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//no sir!!!!!!!!!!!!!!!!!!!!!!!
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		for (int i=1;i<=n;i++){
			if (t1.find(s[i][1])<t1.size()){
				int p=t1.find(s[i][1]);
				string t3=t1;
				int o=0;
				for (int j=p;j<p+s[i][1].size();j++){
					t3[j]=s[i][2][o];
					o++;
				}
				if (t3==t2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
