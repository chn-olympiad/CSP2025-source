#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1,s2;
}words[300001];
bool cmp(node a,node b){
	return a.s1.length()<b.s1.length();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>words[i].s1>>words[i].s2;
	}
	sort(words+1,words+1+n,cmp);
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<'\n';
			continue;
		}
		int l=0,r=0;
		for(int i=0;i<t1.length();i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=0;i<t1.length();i++){
			if(t1[i]!=t2[i]){
				r=i;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(words[i].s1.length()<r-l+1) continue;
			if(t1.length()<words[i].s1.length()) break;
			for(int j=0;j<=l;j++){
//				cerr<<words[i].s1<<' '<<words[i].s2<<' '<<j<<'\n';
				if(t1.substr(j,words[i].s1.length())==words[i].s1&&t2.substr(j,words[i].s2.length())==words[i].s2){
					++cnt;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
} 
