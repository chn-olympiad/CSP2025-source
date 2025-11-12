#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,pos,ans,bg,ed;
string s1[N],s2[N],t1,t2,fd;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	while(q--) {
		cin>>t1>>t2;ans=0;bg=ed=-1;fd="";
		if((int)t1.size()!=(int)t2.size()) {cout<<0<<'\n';continue;}
		for(int i=0;i<(int)t1.size();++i)
			if(t1[i]!=t2[i]) {
				if(bg==-1) bg=i;
				ed=i;
			}
		for(int i=bg;i<=ed;++i) fd+=t1[i];
		bool flag;
		for(int i=1,pos,p1;i<=n;++i) { pos=0;
			while(~(pos=s1[i].find(fd,pos))) {
				p1=pos-1;flag=1;
				for(int j=bg-1;~p1;--j,--p1)
					if(s1[i][p1]!=t1[j]||s2[i][p1]!=t2[j]) {flag=0;break;}
				p1=pos+(int)fd.size();
				for(int j=ed+1;p1<(int)s1[i].size();++j,++p1)
					if(s1[i][p1]!=t1[j]||s2[i][p1]!=t2[j]) {flag=0;break;}
				if(!flag) {pos++;continue;}
				for(int j=bg;j<=ed;++j)
					if(s2[i][pos+j-bg]!=t2[j]) {flag=0;break;}
				if(flag) {ans++;break;}pos++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2 xabcx xadex ab cd bc de aa bb xabcx xadex aaaa bbbb
3 4 a b b c c d aa bb aa b a c b a
*/
