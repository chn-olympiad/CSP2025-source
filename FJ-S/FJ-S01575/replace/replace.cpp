#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
int n,q,a[200010];
pair<int,int> len[200010];
pair<string,string> s[200010];
string t1,t2;
bool f=true;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) {
		cin>>s[i].first>>s[i].second;
		for(int j=0;j<s[i].first.size();j++) {
			if((s[i].first[j]!='a' && s[i].first[j]!='b') || (s[i].second[j]!='a' && s[i].second[j]!='b')) {
				f=false;
			}
		}
	}
	if(f) {
		for(int i=1;i<=n;i++) {
			for(int j=0;j<s[i].first.size();j++) {
				if(s[i].first[j]=='b') {
					len[i].first=j;
					break;
				}
			}
			for(int j=0;j<s[i].second.size();j++) {
				if(s[i].second[j]=='b') {
					len[i].second=j;
					break;
				}
			}
		}
		while(q--) {
			cin>>t1>>t2;
			int len1=0,len2=0,ans=0;
			for(int i=0;i<t1.size();i++) {
				if(t1[i]=='b') {
					len1=i;
					break;
				}
			}
			for(int i=0;i<t2.size();i++) {
				if(t2[i]=='b') {
					len2=i;
					break;
				}
			}
			for(int i=1;i<=n;i++) {
				if(len1>=len[i].first && t1.size()-len1>=s[i].first.size()-len[i].first && len[i].second-len[i].first==len2-len1) {
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(q--) {
		cin>>t1>>t2;
		a[0]=(t1[0]!=t2[0]);
		for(int i=1;i<t1.size();i++) {
			a[i]=a[i-1]+(t1[i]!=t2[i]);
		}
		int ans=0,f=1;
		for(int i=0;i<t1.size();i++) {
			if(i!=0 && a[i-1]!=0) {
				break;
			}
			for(int j=1;j<=n;j++) {
				if(i+s[j].first.size()-1<t1.size()) {
					f=1;
					for(int k=0;k<s[j].first.size();k++) {
						if(t1[i+k]!=s[j].first[k] || t2[i+k]!=s[j].second[k]) {
							f=0;
							break;
						}
					}
					if(f && a[t1.size()-1]==a[i+s[j].first.size()-1]) {
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9'){Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}