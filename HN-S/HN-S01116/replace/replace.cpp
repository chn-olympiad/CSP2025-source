#include<bits/stdc++.h>
using namespace std;
int cnt,flag;
unordered_map<int,int> ma;
vector<pair<string,string> > vec[200007];
vector<int>w[200007];
string ls1,ls2;
void ch(string s1,string s2){
	int sum=0,l=0,r=s1.size()-1;
	while(l<=r&&s1[l]==s2[l]) l++;
	if(l==r) return ;
	while(s1[r]==s2[r]) r--;
	for(int i=l;i<=r;i++) sum*=27,sum+=s1[i]-'a';
	for(int i=l;i<=r;i++) sum*=27,sum+=s2[i]-'a';
	if(!ma[sum]) ma[sum]=++cnt;
	vec[ma[sum]].push_back({s1,s2});
	w[ma[sum]].push_back(l);
}
int sol(string t1,string t2){
	int sum=0,l=0,r=t1.size()-1;
	while(l<=r&&t1[l]==t2[l]) l++;
	while(t1[r]==t2[r]) r--;
	for(int i=l;i<=r;i++) sum*=27,sum+=t1[i]-'a';
	for(int i=l;i<=r;i++) sum*=27,sum+=t2[i]-'a';
	if(!ma[sum]) return 0;
	else{
		int id=ma[sum],ans=0;
		for(int i=0;i<vec[id].size();i++){
			ls1=vec[id][i].first,ls2=vec[id][i].second;flag=1;
			if(l-w[id][i]<0||l+ls1.size()-w[id][i]>t2.size()) continue;
			for(int j=0;j<ls1.size();j++){
				if(t1[l+j-w[id][i]]!=ls1[j]||t2[l+j-w[id][i]]!=ls2[j]){;flag=0;break;}
			}
			ans+=flag;
		}
		return ans;
	}
}
int n,q;
string t1,t2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>t1>>t2;
    	ch(t1,t2);
	}
	while(q--){
		cin>>t1>>t2;
		cout<<sol(t1,t2)<<'\n';
	}
	return 0;
}
/*
ez so quikly easier than t 2
*/
