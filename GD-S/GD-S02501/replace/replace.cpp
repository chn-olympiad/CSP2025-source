#include<bits/stdc++.h>
using namespace std;

int n,q;
string [100010][12],s1,s2,s3[10000],k;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++) {
		cin>>s1>>s2;
		k=1;
		for(int i=0;i<=s.size();i++) {
			if(s1[i]!=s2[i]) {
				s3+=s2[i];
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if(s1==s[i][1]&&s2==s[i][2]) {
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
