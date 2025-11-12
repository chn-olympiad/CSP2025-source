#include<bits/stdc++.h>
using namespace std;
const int N=1e5+12;
string s[N],s1[N];
int h[N][2],ha[N][2],has[2],hash[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
		for(int k=0;k<=s[k].size()-1;k++){
			if(s[i][k]=='b'){
				h[i][0]=k;
				h[i][1]=s[k].size()-1-k;
				break;
			}
		}
		for(int k=0;k<=s1[k].size()-1;k++){
			if(s1[i][k]=='b'){
				ha[i][0]=k;
				ha[i][1]=s1[k].size()-1-k;
				break;
			}
		}
	}
	string ss,sss;
	while(q--){
		cin>>ss>>sss;
		int p,o;
		for(int i=0;i<=ss.size()-1;i++){
			if(ss[i]=='b'){
				has[0]=i;
				has[1]=ss.size()-1-i;
				break;
			}
		}
		for(int i=0;i<=sss.size()-1;i++){
			if(sss[i]=='b'){
				hash[0]=i;
				hash[1]=sss.size()-1-i;break;
			}
		}
		int ans=1;
	    for(int i=1;i<=n;i++){
	    	if(h[i][0]<=has[0]&&h[i][1]<=has[1]
	    	&&ha[i][0]<=hash[0]&&ha[i][1]<=hash[1]
			)
			ans+=1;
		}
		cout<<ans;
	}
	return 0;
}
