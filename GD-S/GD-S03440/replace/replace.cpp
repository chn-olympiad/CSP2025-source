#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+5;
unordered_map<string,vector<int> >um;
int ml1[N],mr1[N],ml2[N],mr2[N];
string s[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		if(s[i][0]==s[i][1])	continue;
		ml1[i]=mr1[i]=-1;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j]){
				ml1[i]=j;
				break;
			}	
		}
		for(int j=s[i][0].size()-1;j>=0;j--){
			if(s[i][0][j]!=s[i][1][j]){
				mr1[i]=j+1;
				break;
			}	
		}
		if(mr1[i]==-1)	mr1[i]=s[i][1].size();
		string ds1=s[i][0].substr(ml1[i],mr1[i]-ml1[i]),ds2=s[i][1].substr(ml1[i],mr1[i]-ml1[i]);
		#define mkp make_pair
		um[ds1+ds2+"q"].push_back(i);
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				ml2[q]=j;
				break;
			}	
		}
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				mr2[q]=j+1;
				break;
			}	
		}
		if(mr2[q]==-1)	mr2[q]=t2.size();
		string ds1=t1.substr(ml2[q],mr2[q]-ml2[q]),ds2=t2.substr(ml2[q],mr2[q]-ml2[q]);
		vector<int>mtv=um[ds1+ds2+"q"];
		int ans=0;
		for(auto id:mtv){
			if(ml2[q]>=ml1[id]&&t1.size()-mr2[q]>=s[id][0].size()-mr1[id]&&
			s[id][0].substr(0,ml1[id])==t1.substr(ml2[q]-ml1[id],ml1[id])&&
			s[id][0].substr(mr1[id],s[id][0].size()-mr1[id])==t1.substr(mr2[q],s[id][0].size()-mr1[id]))	ans++;		
		}
		cout<<ans<<'\n';
	}
	
	return 0;
} 
