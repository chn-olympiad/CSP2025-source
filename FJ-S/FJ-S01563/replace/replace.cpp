#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+5;
string s1[MAXN],s2[MAXN];
int n,q;

void input(){
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
}

int query(string t1,string t2){
	int len1=t1.size();
	int res=0;
	for(int i=1;i<=n;++i){
		int len2=s1[i].size();
		for(int j=0;j<=len1-len2;++j){
			if(t1.substr(j,len2)==s1[i]
			 &&t2.substr(j,len2)==s2[i]) ++res;
		}
	}
	return res;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<query(t1,t2)<<'\n';
	}
	return 0;
}

