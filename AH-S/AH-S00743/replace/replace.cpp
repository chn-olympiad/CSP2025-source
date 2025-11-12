#include<bits/stdc++.h>
using namespace std;
vector<string> s1,s2;
string t1,t2,cpr,cop;
int n,q;
bool cmp(const string &x,const string &y){
	return x.size()<y.size();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x1,x2;
		cin>>x1>>x2;
		if(x1==x2) continue;
		s1.push_back(x1);
		s2.push_back(x2);
	}
	n=s1.size();
	sort(s1.begin(),s1.end(),cmp);
	sort(s2.begin(),s2.end(),cmp);
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		for(int i=0;i<(int)t1.size();i++){
			for(int j=0;j<n;j++){
				if(i+s1[j].size()>t1.size()) break;
				cpr=t1.substr(i,s1[j].size());
				if(cpr==s1[j]){
					cop=t1;
					cop.replace(i,s1[j].size(),s2[j]);
					if(cop==t2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
