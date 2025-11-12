#include<bits/stdc++.h>
#define fi first
#define se second
const int N = 2e5+10;
using namespace std;
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
struct node {int a,b,c,det;}pos[N];
struct edge {int val,id;}tmp[4];
bool cmp(edge x,edge y) {return x.val>y.val;}
int n;long long ans=0;
multiset< pair<int,int> >s[5];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T_T=read();
	while(T_T--) {
		n=read();ans=0;
		for(int i=1;i<=n;i++) {
			tmp[1]={read(),1};tmp[2]={read(),2};tmp[3]={read(),3};
			pos[i]={tmp[1].val,tmp[2].val,tmp[3].val,0};
			sort(tmp+1,tmp+4,cmp);
			pos[i].det=tmp[1].val-tmp[2].val;
			s[tmp[1].id].insert({tmp[1].val,i});
			s[4].insert({pos[i].det,tmp[1].id});
		} int mxid=0,siz=0;
		if((int)s[1].size()>siz) mxid=1,siz=s[1].size();
		if((int)s[2].size()>siz) mxid=2,siz=s[2].size();
		if((int)s[3].size()>siz) mxid=3,siz=s[3].size();
		for(int i=1;i<=3;i++) for(auto v:s[i]) ans=ans+v.fi;
		if((n%2==0&&siz>n/2)||(n%2&&siz>=n/2+1)) {
			int f=(n%2)?(siz-n/2):(siz-n/2);
			for(auto v:s[4]) {
				if(v.se==mxid) {
					ans=ans-v.fi;f--;
				}if(!f) break;
			}
		}
		printf("%lld\n",ans);
		s[1].clear();s[2].clear();s[3].clear();s[4].clear();
	}
	return 0;
}
