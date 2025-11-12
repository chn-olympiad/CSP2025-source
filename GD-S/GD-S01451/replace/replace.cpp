#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][2];
string t1,t2;
vector<int>kmp(string s1,string s2){
	s2=s1+'|'+s2;
	vector<int>nxt(s2.size());
	for(int i=1;i<s2.size();++i){
		int p=nxt[i-1];
		while(p!=0&&s2[i]!=s2[p]) p=nxt[p];
		if(s2[i]==s2[p]) nxt[i]=p+1;
//		cout<<"kmp\n";
	}
	return nxt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		cin>>t1>>t2;
		int l,r,cnt=0;
		for(int i=0;i<t1.size();++i){
			if(t1[i]!=t2[i]){
				l=i;break;
			}
		}
		for(int i=t1.size()-1;i>=0;--i){
			if(t1[i]!=t2[i]){
				r=i;break;
			}
		}
		for(int i=1;i<=n;++i){
			auto n1=kmp(s[i][0],t1),n2=kmp(s[i][1],t2);
//			for(int x:n1) cout<<x<<' ';
//			cout<<endl;
//			for(int x:n2) cout<<x<<' ';
//			cout<<endl;
			for(int i=0;i<t1.size();++i){
				if(n1[i+n+1]==s[i][0].size()&&n2[i+n+1]==s[i][1].size()){
					if(i>=r&&i-s[i][0].size()+1<=l){
						++cnt;
						break;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

