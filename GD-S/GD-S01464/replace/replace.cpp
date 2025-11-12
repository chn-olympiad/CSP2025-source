#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,q,sum,aa[N][3],bb[N][3],cc[3],dd[3];
string s[N][3],t[N][3],t1,t2,p;
bool check(ll a,ll b) {
	p=t1;
	if(s[b][1].size()>t1.size()-a) {
		return false;
	}
	for(int i=0;i<s[b][1].size();i++) {
		if(t1[a+i]!=s[b][1][i]) {
			return false;
		}
		p[a+i]=s[b][2][i];
	}
	if(p!=t2) {
		return false;
	}
	return true;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++) {
		cin>>t[i][1]>>t[i][2];
	}
	if(n<=100&&q<=100) {
		for(int i=1;i<=q;i++) {
			t1=t[i][1],t2=t[i][2];
			sum=0;
			for(int j=0;j<t1.size();j++) {
				for(int k=1;k<=n;k++) {
					if(t1[j]==s[k][1][0]&&t2[j]==s[k][2][0]) {
						if(check(j,k)) {
							sum++;
						}
					} 
				} 
			}
			cout<<sum<<'\n';
		}
	} else {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<s[i][1].size();j++) {
				if(s[i][1][j]='b') {
					aa[i][1]=j+1;
					aa[i][2]=s[i][1].size()-aa[i][1]-1;
					break;
				}
			}
			for(int j=1;j<s[i][2].size();j++) {
				if(s[i][2][j]='b') {
					bb[i][1]=j+1;
					bb[i][2]=s[i][2].size()-bb[i][1]-1;
					break;
				}
			}
		}
		for(int i=1;i<=q;i++) {
			sum=0;
			t1=t[i][1],t2=t[i][2];
			for(int j=1;j<t1.size();j++) {
				if(t1[j]='b') {
					cc[1]=j+1;
					cc[2]=t1.size()-j;
					break;
				}
			}
			for(int j=1;j<t2.size();j++) {
				if(t2[j]='b') {
					dd[1]=j+1;
					dd[2]=t2.size()-j;
					break;
				}
			}
			for(int j=1;j<=n;j++) {
				if(aa[j][1]<=cc[1]&&aa[j][2]<=cc[2]&&bb[j][1]<=dd[1]&&bb[j][2]<=dd[2]) {
					if(aa[j][1]-bb[j][1]==cc[1]-dd[1]) {
						sum++;
					}
				}
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}
