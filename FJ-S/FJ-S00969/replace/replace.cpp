#include<bits/stdc++.h>
using namespace std;
string s[200005],s1[200005];
string t[200005],t1[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1; i<=q; i++){
		cin>>t[i]>>t1[i];
	}
	for(int i=1; i<=q; i++){
		int ans=0;
		for(int j=1; j<=n; j++){
			int l=t[i].find(s[j]);
			if(l==-1)continue;
			string a=t[i];
			a.replace(l,s1[j].size(),s1[j]);
			if(a==t1[i])ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
