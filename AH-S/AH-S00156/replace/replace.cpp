#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string str1[N],str2[N],str3[N];
int n,q,ans[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>str1[i]>>str2[i];
	for(int i=1;i<=q;i++){
		string x,y;cin>>x>>y;
		if(x.size()!=y.size()) cout<<"0\n";
		else{
			int ans=0;
			for(int j=1;j<=n;j++){
				if(x.find(str1[j])<0||x.find(str1[j])>=x.size()) continue;
				if(x.find(str1[j])==y.find(str2[j])){
					bool flag=1;
					for(int i=(int)x.find(str1[j])+(int)str1[j].size();i<(int)x.size();i++){
						if(x[i]!=y[i]){
							flag=0;
							break;
						}
					}
					ans+=flag;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
