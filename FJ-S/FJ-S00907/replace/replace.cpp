#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[1005],s2[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+(int)s1[i].size()-1<(int)a.size();j++){
				if(a.substr(j,s1[i].size())==s1[i]&&b.substr(j,s1[i].size())==s2[i]){
					if(a.substr(0,j)+s1[i]+a.substr(j+(int)s1[i].size(),(int)a.size()-j-(int)s1[i].size())==a&&b==a.substr(0,j)+s2[i]+a.substr(j+(int)s1[i].size(),(int)a.size()-j-(int)s1[i].size())){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
