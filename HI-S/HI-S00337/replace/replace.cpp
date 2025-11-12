#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[2][N],t1,t2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[0][i]>>s[1][i];
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int tp=t1.find(s[0][i],0);
			while(true){
				string tmp=t1;
				for(int j=tp;j<tp+s[0][i].size();j++)tmp[j]=s[1][i][j-tp];
				if(tmp==t2)ans++;
				tp=t1.find(s[0][i],tp+1);
				if(tp==-1)break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

