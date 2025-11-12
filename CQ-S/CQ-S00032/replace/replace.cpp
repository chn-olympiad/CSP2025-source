#include<bits/stdc++.h>
using namespace std;
string org[200005],now[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>org[i]>>now[i];
	while(q--){
		string s,t;
		cin>>s>>t;
		int ls=s.size(),ans=0;
		for(int i=0;i<ls;i++){
			for(int j=1;j<=ls-i;j++){
				for(int k=1;k<=n;k++){
					if(s.substr(i,j)==org[k]){
						if(s.substr(0,i)+now[k]+s.substr(i+j,ls-i-j)==t) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}
