#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1003;
int n,q;
string s[N][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		string q1,q2;
		cin>>q1>>q2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos=q1.find(s[i][1]);
			if(~pos){
				if(q1.substr(0,pos)+s[i][2]+q1.substr(pos+s[i][1].size(),q1.size())==q2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

