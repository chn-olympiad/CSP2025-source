#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
const int N=2e5+5;
string s[N],s1[N];
int main(){
	//freopen("replace3.in","r",stdin);
	//freopen("replace3.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	while(q--){
		string ss,ss1;
		cin>>ss>>ss1;
		int ans=0;
		if(ss.size()!=ss1.size()){
			cout<<0<<endl;
			continue;
		}
		else{
			for(int i=0;i<ss.size();i++){
				for(int j=1;j<=n;j++){
					if(ss[i]==s[j][0]){
						int l=1,p=0;
						while(l<s[j].size()){
							if(ss[i+l]!=s[j][l]){
								p=1;
								break;
							}
							l++;
						}
						if(p==0){
							string ss3=ss;
							l=0;
							while(l<s1[j].size()){
								ss3[i+l]=s1[j][l];
								l++;
							}
							int p1=0;
							for(int i=0;i<ss3.size();i++){
								//cout<<ss3[i];
								if(ss3[i]!=ss1[i]){
									p1=1;
									break;
								}
							}
							//cout<<endl;
							if(p1==0){
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
