#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N],t[N],S,T;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s[i]>>t[i];
	while (q--){
		cin>>S>>T;
		string to;int ans=0;
		for (int i=1;i<=n;i++)
			for (int p=0;p+s[i].size()-1<S.size();p++)
				if (s[i][0]==S[p]){
					bool f=true;to=S;
					for (int j=0;j<s[i].size();j++){
						to[j+p]=t[i][j];
						if (s[i][j]!=S[j+p]){
							f=false;
							break;
						}
					}
					ans+=(f&&to==T);
				}
		cout<<ans<<'\n';
	}
	return 0;
}
