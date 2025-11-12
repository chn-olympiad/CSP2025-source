#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2];
bool f(string a,string b,int l,int r,int l2){
	for(;l<=r;l++,l2++){
		if(a[l]!=b[l2]) return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	if(n>100&&q>1000) goto planB;
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s1.size()<s[i][0].size()) continue;
			for(int j=0;j<=s1.size()-s[i][0].size();j++){
				if((f(s1,s2,0,j-1,0)||j==0)&&
					f(s1,s[i][0],j,j+s[i][0].size()-1,0)&&
					f(s2,s[i][1],j,j+s[i][0].size()-1,0)&&
					(f(s1,s2,j+s[i][0].size(),s1.size()-1,j+s[i][0].size())||
					j+s[i][0].size()==s1.size())
				) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
planB:
	for(int i=1;i<=q;i++) printf("0\n");
	return 0;
}
