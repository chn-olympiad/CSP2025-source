#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
struct nd {
	string s1,s2;
} s[200010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1>>s2;
		int h=-1,len=min(s1.size()-1,s2.size()-1);
		while(h+1<=len&&s1[h+1]==s2[h+1]) h++;
		if(s1.size()!=s2.size()) {
			int len1=s1.size()-1,len2=s2.size()-1;
			for(int j=h; j<len1; j++) s[i].s1+=s1[j];
			for(int j=h; j<len2; j++) s[i].s2+=s2[j];
		} else {
			while(s1[len]==s2[len]) len--;
			for(int j=h; j<=len; j++) {
				s[i].s1+=s1[j];
				s[i].s2+=s2[j];
			}
		}

	}
	string k1,k2;
	s1=s2="";
	long long ans=0;
	for(int i=1; i<=q; i++) {
		cin>>s1>>s2;
		if(s1==s2) ans++;
		int h=-1,len=min(s1.size()-1,s2.size()-1);
		while(h+1<=len&&s1[h+1]==s2[h+1]) h++;
		if(s1.size()!=s2.size()) {
			int len1=s1.size()-1,len2=s2.size()-1;
			for(int j=h; j<len1; j++) s[i].s1+=s1[j];
			for(int j=h; j<len2; j++) s[i].s2+=s2[j];
		} else {
			while(s1[len]==s2[len]) len--;
			for(int j=h; j<=len; j++) {
				k1+=s1[j];
				k2+=s2[j];
			}
		}
		for(int j=1; j<=n; j++)
			if(s[j].s1==k1&&s[j].s2==k2) ans++;
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
