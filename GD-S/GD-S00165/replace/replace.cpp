#include<bits/stdc++.h>
using namespace std;
int t1[2500005][26],t2[2500005][26],cnt1=1,cnt2=1;
int id1[2500005],id2[2500005];
void add1(string s,int id){
	int rt=1;
	for (auto&i:s){
		if (t1[rt][i-'a'])rt=t1[rt][i-'a'];
		else t1[rt][i-'a']=++cnt1,rt=cnt1;
	}
	id1[rt]=id;
}
void add2(string s,int id){
	int rt=1;
	for (auto&i:s){
		if (t2[rt][i-'a'])rt=t2[rt][i-'a'];
		else t2[rt][i-'a']=++cnt2,rt=cnt2;
	}
	id2[rt]=id;
}
string l1,l2;
int query(){
	if (l1.size()!=l2.size())return 0;
	int l=0,r=0;
	for (int i=0;i<l1.size();i++){
		if (l1[i]!=l2[i]){
			l=i;break;
		}
	}
	for (int i=l1.size()-1;i>=0;i--){
		if (l1[i]!=l2[i]){
			r=i;break;
		}
	}
	int res=0;
	for (int i=0;i<=l;i++){
		int rt1=1,rt2=1;
		for (int j=i;j<l1.size();j++){
			if (!t1[rt1][l1[j]-'a']||!t2[rt2][l2[j]-'a'])break;
			rt1=t1[rt1][l1[j]-'a'],rt2=t2[rt2][l2[j]-'a'];
			if (j>=r&&id1[rt1]&&id2[rt2]&&id1[rt1]==id2[rt2])res++;
		}
	}
	return res;
}
int n,q;
signed main(){
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	//fropen("rplace.in","r",stdin),freopen("rrplace.out","w",stdout); 
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		add1(s1,i),add2(s2,i);
	}
	while(q--){
		cin>>l1>>l2;
		cout<<query()<<'\n';
	}
	return 0;
}
