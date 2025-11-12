#include<bits/stdc++.h>
using namespace std;
const int N=200010;
string s1[N],s2[N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string ss1,ss2;
		cin>>ss1>>ss2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s1[i].size()>ss1.size())continue;
			for(int j=0;j<ss1.size()-s1[i].size()+1;j++){
				bool fl=1;
				for(int k=j;k<j+s1[i].size();k++){
					if(s1[i][k-j]!=ss1[k]){
						fl=0;
						break;
					}
				}
				if(fl){
					bool tt=1;
					for(int k=j;k<j+s1[i].size();k++){
						if(ss2[k]!=s2[i][k-j]){
							tt=0;
							break;
						}
					} 
					if(tt){
						for(int k=j+s1[i].size();k<ss1.size();k++){
							if(ss1[k]!=ss2[k]){
								tt=0;
								break;
							}
						}
					}
					if(tt)ans++;
//					if(tt)cout<<j<<endl;
				}
				if(ss1[j]!=ss2[j])break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
