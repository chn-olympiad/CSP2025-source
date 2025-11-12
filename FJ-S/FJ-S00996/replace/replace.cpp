#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N][5],t1,t2;
int n,q,ans,l[N],minl=INT_MAX,t[30],f=0;
int s1[N],s2[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s[i][1]>>s[i][2];
		l[i]=s[i][1].size();
	}
	while(q--) {
		cin>>t1>>t2;
		ans=0;
		int len=t1.size();
		if(len<minl) {
			cout<<0<<"\n";
		} else {
			for(int i=0;i<=len;i++){
				for(int j=i+1;j<=len;j++){
					for(int k=1;k<=n;k++){
						if(j-i==l[k]){
							for(int ii=i;ii<=j;ii++){
								if(t1[ii-i]==s[k][1][ii-i]&&t2[ii-i]==s[k][2][ii-i]){
									ans++;
								}
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
