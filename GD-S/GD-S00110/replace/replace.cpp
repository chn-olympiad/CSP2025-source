#include<bits/stdc++.h>
# define Maxn 200005
# define Maxm 5000005
# define ll unsigned long long
# define mod 1771274171713
using namespace std;
int n,q,len1,len2,l,r;
char s[Maxm],t[Maxm];
ll w[Maxm],h1[Maxm],h2[Maxm];
struct Node{int l,r;ll L,R;};
map<pair<ll,ll>,vector<Node>> mp;
struct Ask{int l,r,len,bz1,bz2,id;}ask[Maxn];
int sum[Maxn];
bool cmp(Ask x,Ask y) {return x.l<y.l;}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q),w[0]=1;
	for(int i=1;i<=5000000;i++)
	w[i]=w[i-1]*mod;
	for(int i=1;i<=n;i++) {
		scanf("%s%s",s+1,t+1);
		len1=strlen(s+1),l=0,r=0;
		for(int j=1;j<=len1;j++) {
			if(s[j]!=t[j]) {
				if(!l) l=j;
				r=j;
			}
		}
		ll L=0,R=0,Smid=0,Tmid=0;
		if(l&&r) {
			for(int j=l;j<=r;j++) {
				Smid=Smid*mod+s[j];
				Tmid=Tmid*mod+t[j];
			}
			for(int j=1;j<=l-1;j++)
			L=L*mod+s[j];
			for(int j=r+1;j<=len1;j++)
			R=R*mod+s[j];
			mp[{Smid,Tmid}].push_back(Node{l-1,len1-r,L,R});
		}
	}
	while(q--) {
		scanf("%s%s",s+1,t+1);
		len1=strlen(s+1),len2=strlen(t+1),l=0,r=0;
		if(len1!=len2) {printf("0\n");continue;}
		for(int j=1;j<=len1;j++) {
			if(s[j]!=t[j]) {
				if(!l) l=j;
				r=j;
			}
		}
		ll Smid=0,Tmid=0;
		int ans=0;
		for(int j=l;j<=r;j++) {
			Smid=Smid*mod+s[j];
			Tmid=Tmid*mod+t[j];
		}
		for(int j=l-1;j>=1;j--)
		h1[l-j]=s[j]*w[l-1-j]+h1[l-j-1];
		for(int j=r+1;j<=len1;j++)
		h2[j-r]=h2[j-r-1]*mod+s[j];
		for(Node Now:mp[{Smid,Tmid}]) {
			if(Now.l<=l-1&&Now.r<=len1-r&&h1[Now.l]==Now.L&&h2[Now.r]==Now.R)
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
