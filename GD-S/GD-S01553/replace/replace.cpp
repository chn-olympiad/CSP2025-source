#include<iostream>
using namespace std;
int n,q;
struct str {
	string s1,s2,p;
	int same,dl,pl;
}s[200005];
string t1,t2;
int calc() {
	int res=0,len=t1.size(),di;
	for(int i=0;i<len;i++) {
		if(t1[i]!=t2[i]) {
			di=i;
			break;
		}
	}
	for(int i=1;i<=n;i++) {
		if(di<s[i].pl||len-di<s[i].dl||s[i].same) continue;
		int f=1,pl=s[i].pl;
		for(int j=0;j<pl;j++) {
			char c=s[i].p[pl-j-1];
			if(c!=t1[di-j-1]||c!=t2[di-j-1]) {f=0;break;}
		}
		if(!f) continue;
		for(int j=0;j<s[i].dl;j++) {
			if(s[i].s1[pl+j]!=t1[di+j]||s[i].s2[pl+j]!=t2[di+j]) {f=0;break;}
		}
		if(!f) continue;
		for(int j=di+s[i].dl;j<len;j++) if(t1[j]!=t2[j]) {f=0;break;}
		res+=f;
	}
	return res;
}
void work() {
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i].s1>>s[i].s2;
		int len=s[i].s1.size();
		for(int j=0;j<len;j++) {
			int c1=s[i].s1[j];
			if(c1==s[i].s2[j]) s[i].p+=c1;
			else break;
		}
		s[i].pl=s[i].p.size();
		if(s[i].pl==len) s[i].same=1;
		else s[i].dl=s[i].s1.size()-s[i].pl;
	}
	while(q--) {
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<"0\n";
		else cout<<calc()<<'\n';
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t=1;
//	cin>>t;
	while(t--) {
		work();
	}
	return 0;
}
