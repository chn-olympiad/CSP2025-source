#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<string> v1,v2;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		v1.push_back(s);
		cin>>s;
		v2.push_back(s);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=1;i<=q;i++){
		int s=0;
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=0;i<t1.size();i++){
			for(int p=lower_bound(v1.begin(),v1.end(),to_string(t1[i]-1))-v1.begin(),j;p<v1.size()&&v1[p][0]==t1[i];p++){
				for(j=0;i+j<t1.size()&&j<v1[p].size();j++){
					//cout<<'@'<<i<<','<<i+j<<'\n';
					if(t1[i+j]!=v1[p][j]) goto T_END;
					if(t2[i+j]!=v2[p][j]) goto T_END;
				}
				for(;i+j<t1.size();j++){
					if(t1[i+j]!=t2[i+j]) goto T_END;
				}
				s++;
				T_END:
			}
			//cout<<t1[i]<<','<<t2[i]<<'\n';
			if(t1[i]!=t2[i]) break;
		}
		cout<<s<<'\n';
	}
	return 0;
}
