#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> a[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		vector<int> x;
		for(int j=0;j<=(int)s1.size();++j){
			if(s1[j]!=s2[j]){
				x.push_back(j);
			}
		}
		for(int i=1;i<=n;++i){
			bool is1=true,is2=true;
			if((int)a[i].first.size()==(int)x.size()){
				int cnt=-1;
				for(int j:x){
					if(s1[j]!=a[i].first[cnt++]){
						is1=false;
					}
				}
				cnt=-1;
				for(int j:x){
					if(s2[j]!=a[i].second[cnt++]){
						is2=false;
					}
				}
			}
			if(is1&&is2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
