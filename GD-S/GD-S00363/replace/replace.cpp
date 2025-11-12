#include<bits/stdc++.h>
using namespace std;
long n,q,cnt;
string s1[210010],s2[210010],q1,q2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	for(long i=1; i<=q; i++) {
		cin>>q1>>q2;
		cnt=0;
		for(long j=1; j<=n; j++) {
			if(q1.find(s1[j])!=std::string::npos&&q2.find(s2[j])!=std::string::npos&&q1.find(s1[j])==q2.find(s2[j])) {
				string a=q1,b=q2,c=q1,d=q2;
				a=a.substr(0,q1.find(s1[j]));
				b=b.substr(0,q2.find(s2[j]));
				c.erase(0,q1.find(s1[j])+s1[j].size());
				d.erase(0,q2.find(s2[j])+s2[j].size());
				if(a==b&&c==d) {
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
