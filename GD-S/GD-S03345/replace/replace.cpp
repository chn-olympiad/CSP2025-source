#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const ll mod = 998244353;
int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-'){w=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*w;
}
int n,q;

ll ans;
string s1[N],s2[N];
char s[N],z[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i = 1;i <= n;++i){
		cin >> s1[i] >> s2[i];
	}int len,m;
	while(q--){
		int ans = 0;
		scanf("%s",s+1);
		scanf("%s",z+1);
		len = strlen(s+1);
		int flag=0;int ls=len+1,rs=0;
		while(s[ls-1]==z[ls-1])--ls;
		while(s[rs+1]==z[rs+1])++rs;
		for(int k = 1;k <= n;++k){
			m = s1[k].size();
			if(len<m)continue;
			for(int i = max(1,ls-m);i <= min(len,rs+m);++i){
				if(s[i]==s1[k][0]&&z[i]==s2[k][0]){
					flag=1;
					for(int j = 1;j < m;++j){
						if(s[i+j]!=s1[k][j]||z[i+j]!=s2[k][j]){
							flag=0;
							break;
						}
					}
					ans+=flag;
				}
				if(flag)break;
				if(s[i]!=z[i])break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
