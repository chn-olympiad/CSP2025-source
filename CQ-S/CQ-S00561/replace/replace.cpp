#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10;
int n,q;
int cnt;
vector<int>to[N];
char s1[N],s2[N];
struct node{
	int son[27];
	
}tr[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s\n",s1+1,s2+1);
		int l=0,r=0,s=0,t=0;
		for(int i=1;s1[i];i++){
			if(s1[i]!=s2[i]){
				if(!l)l=i;
				r=i;
			}
		}
		for(int i=l;i<=r;i++){
			int ch=s1[i]-'a';
			if(!tr[s].son[ch])tr[s].son[ch]=++cnt;
			s=tr[s].son[ch]; 
		}
		for(int i=l;i<=r;i++){
			int ch=s2[i]-'a';
			if(!tr[t].son[ch])tr[t].son[ch]=++cnt;
			t=tr[t].son[ch]; 
		}
		to[s].push_back(t);
	}
	for(int i=1;i<=q;i++){
		scanf("%s %s\n",s1+1,s2+1);
		int l=0,r=0,t=0,now=0,ans=0;
		for(int i=1;s1[i];i++){
			if(s1[i]!=s2[i]){
				if(!l)l=i;
				r=i;
			}
		}
		for(int i=l;i<=r;i++){
			int ch=s2[i]-'a';
			if(!tr[t].son[ch]){
				tr[t].son[ch]=++cnt;
			}
			t=tr[t].son[ch]; 
		}
		for(int i=l;i<=r;i++){
			int ch=s1[i]-'a';
			if(!tr[now].son[ch])tr[now].son[ch]=++cnt;
			now=tr[now].son[ch]; 
		}
		for(int s:to[now]){
			if(s==t)ans++;
		}
		printf("%lld\n",ans);	
	}
	return 0;
} 
