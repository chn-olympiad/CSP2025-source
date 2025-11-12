#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
map<pair<string,string>,int> mp;
string s1,s2,t1,t2;
int n,q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[make_pair(s1,s2)]++;
	}
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		string pt1,pt2;
		for(int i=0;i<=t1.size();i++){
			if(pt1!=pt2) break;
			string st1,st2;
			for(int j=i;j<t1.size();j++){
				st1+=t1[j],st2+=t2[j];
//				cout<<i<<" "<<j<<" "<<st1<<" "<<st2<<" "<<t1.substr(j+1,t1.size()-j-1)<<","<<t2.substr(j+1,t2.size()-j-1)<<endl;
				if(j+1<t1.size()&&t1.substr(j+1,t1.size()-j-1)!=t2.substr(j+1,t2.size()-j-1)) continue;
				ans+=mp[make_pair(st1,st2)];
			}
			pt1+=t1[i],pt2+=t2[i];
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
