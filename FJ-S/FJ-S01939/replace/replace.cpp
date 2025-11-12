#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s[200005][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<endl;
			continue;
		}
		string k,m;
		for(int i=1;i<=n;i++){
			string si=s[i][0];
			for(int j=0;j<=int(k.size()-si.size());j++){
				k=t[0];
				m="";
				for(int l=j;l<int(j+si.size());l++)m+=k[l];
				if(m==si){
					for(int l=j;l<int(j+si.size());l++){
						k[l]=s[i][1][l-j];
					}
					if(k==t[1])ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0; 
	}
	return 0;
}
