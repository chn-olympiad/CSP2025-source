#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][2],t,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	auto no=t.find("-");
	while(q--){
		cin>>t>>tt;
		int ans=0;
		for(int i=1;i<=n;i++){
			auto g=t.find(s[i][0]);
			if(g==no)continue;
			string v=t;
			int len=s[i][0].size();
			for(int j=g,k=0;k<s[i][0].size();k++){
				v[j+k]=s[i][1][k];
			}
			if(v==tt){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

