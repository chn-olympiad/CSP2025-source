#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,t1,t2;
struct node{
	int l,r;
};
vector<node> G[10000005];
int main(){
	freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int pos1,pos2;
		for(int j=0;j<(int)s1.size();j++) if(s1[j]=='b') pos1=j;
		for(int j=0;j<(int)s2.size();j++) if(s2[j]=='b') pos2=j;
		G[pos1-pos2+5000000].push_back({pos1,(int)s1.size()-pos1});
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int pos1,pos2;
		for(int j=0;j<(int)t1.size();j++) if(t1[j]=='b') pos1=j;
		for(int j=0;j<(int)t2.size();j++) if(t2[j]=='b') pos2=j;
		if(t1.size()!=t2.size()) {
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<(int)G[pos1-pos2+5000000].size();i++) if(G[pos1-pos2+5000000][i].l<=pos1&&G[pos1-pos2+5000000][i].r<=(int)t1.size()-pos1) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
