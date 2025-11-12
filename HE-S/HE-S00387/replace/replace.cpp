#include <bits/stdc++.h>
using namespace std;
string s1[100010],s2[100010],t1[100010],t2[100010];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=n;i++){
		if(s1[i]==t1[i] || s1[i]==t2[i] || s2[i]==t1[i] || s2[i]==t2[i])ans++;
	}
	for(int i=1;i<=q;i++){
		cout<<ans;
	}
	return 0;
}
