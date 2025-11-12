#include<bits/stdc++.h>
#define pss pair<string,string>
using namespace std;
int n,q;
string s1,s2,t1,t2;
int ct;
map<pair<string,string>,int>S;
int ans[200010],re[200010];
int ls,lt;
pss cl(string s1,string s2){
	int len=s1.length();
	int l=0;
	while(s1[l]==s2[l]&&l<=len) l++;
	if(l){
		s1.erase(0,l);
		s2.erase(0,l);
	}
	
	len=s1.length();
	l=len-1;
	while(s1[l]==s2[l]&&l>=0) l--;
	if(l<len-1){
		s1.erase(l+1,len-1);
		s2.erase(l+1,len-1);
	}
	return make_pair(s1,s2);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		if(s1==s2) continue;
		pss s=cl(s1,s2);
//		pss s={s1,s2};
		S[s]++;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		pss t=cl(t1,t2);
		if(S.count(t)) printf("%d\n",S[t]);
		else printf("0\n");
	}
	return 0;
}
