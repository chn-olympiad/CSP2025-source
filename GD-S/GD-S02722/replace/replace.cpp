#include<bits/stdc++.h>
#define TIMU (string)"replace"
#define ll long long
#define ull unsigned long long
using namespace std;
struct th_{
	string a,b;
};
vector<th_> vt;
int th_cnt(string s1,string s2,string a,string b){
	int cnt = 0;
	//cout<<"s1="<<s1<<" s2="<<s2<<" a="<<a<<" b="<<b<<endl;
	//cout<<"s1.size()-a.size()+1="<<s1.size()-a.size()+1<<endl;
	for(register int i = 0;i<(int)s1.size()-a.size()+1 && s1.size()>=a.size();i++){
		string sub = s1.substr(i,a.size());
		//cout<<"  i="<<i<<" sub="<<sub<<endl;
		if(sub==a){
			string ns = s1.substr(0,i)+b+s1.substr(i+a.size());
			if(ns==s2){
				/*cout<<"s1="<<s1<<" s2="<<s2<<" a="<<a<<" b="<<b<<endl;
				cout<<"s1.size()-a.size()+1="<<s1.size()-a.size()+1<<endl;
				cout<<"  i="<<i<<" sub="<<sub<<endl;
				cout<<"    ns="<<ns<<" cnt="<<cnt<<endl;*/
				cnt++;
			}
		}
	}
	return cnt;
}
string s1,s2;
int n,q;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		string t1,t2;
		cin>>t1>>t2;
		vt.push_back({t1,t2});
	}
	while(q--){
		cin>>s1>>s2;
		int ans = 0;
		for(register int i = 0;i<n;i++){
			int r = th_cnt(s1,s2,vt[i].a,vt[i].b);
			ans+=r;
		}
		cout<<ans<<endl;
	}
	return 0;
}

