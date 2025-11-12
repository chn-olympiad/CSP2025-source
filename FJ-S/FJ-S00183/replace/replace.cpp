#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,sz,ans[N];
string s[N][2],t[N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2],sz+=s[i][1].size()+s[i][2].size();
	for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2],sz+=t[i][1].size()+t[i][2].size();
	if(n<=1000&&q<=1000&&sz<=10000){
		for(int i=1;i<=q;i++){
			if(t[i][1].size()!=t[i][2].size())continue;
			for(int j=1;j<=n;j++){
				if(t[i][1].size()<s[j][1].size())continue;
				for(int k=0;k<=t[i][1].size()-s[j][1].size();k++){
					string tmp=t[i][1];
					int f=1;
					for(int o=0;o<s[j][1].size();o++){
						if(t[i][1][o+k]!=s[j][1][o]){
							f=0;continue;
						}
						tmp[o+k]=s[j][2][o];
					}
					if(f&&tmp==t[i][2])ans[i]++;
				}
			}
		}
		for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
