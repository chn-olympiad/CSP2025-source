#include<bits/stdc++.h>
using namespace std;
struct node{
	string c1;
	string c2;
}s[200000+5];
node t[200000+5];
int n,q,ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int i,j,k,p;
	for(i=1;i<=n;i++){
		cin>>s[i].c1>>s[i].c2;
	}
	for(i=1;i<=q;i++) {
		ans=0;
		cin>>t[i].c1>>t[i].c2;
		for(k=1;k<=n;k++) {
			bool flag=1;
			for(j=0;j<t[i].c1.size();j++){
				if(t[i].c1[j]==s[k].c1[0]) {
					flag=0;
					for(p=0;p<s[k].c1.size();p++){
						if(t[i].c1[j+p]!=s[k].c1[p] or s[k].c2[p]!=t[i].c2[j+p]) flag=1;continue;
					}
					if(!flag) {
						for(p=0;p<s[k].c1.size();p++){
							t[i].c1[j+p]=s[k].c1[p];
						}
						continue;
					}
				}
			}
		}
		bool flag=0;
		for(j=0;j<t[i].c1.size();j++) {
			if(t[i].c1[j]!=t[i].c2[j]) flag=1;
		}
		if(flag==0) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
