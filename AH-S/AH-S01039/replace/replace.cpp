#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,b[N][3];
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for (int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		if (t1==t2){
			cout<<0<<'\n';
			continue;
		}
		for (int j=1;j<=n;j++)
			if ((int)t1.find(s1[i])!=-1 && t1.find(s1[i]) == t2.find(s2[i])) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
