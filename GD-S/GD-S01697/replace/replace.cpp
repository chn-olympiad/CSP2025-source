//By Dream_Flynn(luogu name)
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
map<string,string> mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(T--){
		string sx,sy;
		cin>>sx>>sy;
		if(sx.length()!=sy.length()){
			cout<<0<<"\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<sx.length();i++){
			for(int j=i;j<sx.length();j++){
				string t1="",t2="";
				for(int k=i;k<=j;k++){
					t1+=sx[k];
					t2+=sy[k];
				}
				if(mp[t1]==t2){
					string t3="";
					for(int l=0;l<i;l++){
						t3+=sy[l];
					}
					t3+=t1;
					for(int l=j+1;l<sy.length();l++){
						t3+=sy[l];
					}
					//cerr<<t3<<endl;
					if(sx==t3){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
