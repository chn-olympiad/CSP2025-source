#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
ll n,q,ans;
string s[MAXN][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		ans=0;
		string t1,t2,rep;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			rep=t1;
			ll f=t1.find(s[i][0]);
			if(f!=-1){
				for(int j=0;j<s[i][0].size();j++){
					rep[f+j]=s[i][1][j];
				}
				if(rep==t2)ans++;
				//cout<<rep<<' '<<s[i][0]<<endl;
			}
		}
		cout<<ans<<endl;
	}
//	system("fc replace.out replace3.ans");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
