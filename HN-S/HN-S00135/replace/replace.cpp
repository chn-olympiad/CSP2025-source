#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string s,t;
		cin>>s>>t;
		int ans=0;
		int nn=s.size();
		for(int i=1;i<=n;i++){
			int nc=s1[i].size();
			for(int j=0;j<nn;j++){
				bool used=0;
				for(int k=0;k<nc;k++){
					if(j+k>=nn){
						used=1;
						break;
					}
					if(s[j+k]!=s1[i][k]||t[j+k]!=s2[i][k]){
						used=1;
						break;
					}
				}
				if(!used){
					for(int k=0;k<nn;k++)if(k<j||k>=j+nc){
						if(s[k]!=t[k]){
							used=1;
							break;
						}
					}
					if(!used)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}