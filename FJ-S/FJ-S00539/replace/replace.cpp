#include<bits/stdc++.h>
using namespace std;
string s1[10010],s2[10010];
string sub(int l,int r,string a) {
	string res="";
	for(int i=l;i<=r;i++) {
		res+=a[i];
	}
	return res;
}
string rep(int l,int r,string a,string b) {
	string res="";
	int cnt=0;
	for(int i=0;i<a.size();i++) {
		if(i>=l&&i<=r) {
			res+=b[cnt];
			++cnt;
		}
		else res+=a[i];
	}
	return res;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		string a,b;
		cin>>a>>b;
		int len=a.size();
		int ans=0;
		for(int i=0;i<len;i++) {
			for(int j=i;j<len;j++) {
				string r=sub(i,j,a);
				for(int k=1;k<=n;k++) {
					if(r==s1[k]) {
						string rr=rep(i,j,a,s2[k]);
						//cout<<i<<" "<<j<<" "<<a<<" "<<s2[k]<<"\n";
						//cout<<rr<<"\n";
						if(rr==b) {
							ans++;
						}
					}
				}
			}
		} 
		cout<<ans<<"\n";
	}
	return 0;
}
