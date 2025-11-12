#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e7+5;
struct Node{
	string s1,s2;
}a[N],b[N];
struct NODE{
	int x,y,id;
};
int n,m,lm[N],rm[N],dm[N],ans[N],c[M],V=0;
bool o=1;
vector<NODE>s[M];
void read(string &str){
	str.clear();
	char c=getchar();
	int cnt=0;
	for(;c<'a'||c>'z';c=getchar());
	for(;c>='a'&&c<='z';c=getchar()){
		if(c>'b'||c=='b'&&++cnt>1)o=0;
		str.push_back(c);
	}
}
void update(int x,int d){
	for(;x<=V;x+=x&-x)c[x]+=d;
}
int query(int x){
	int s=0;
	for(;x;x-=x&-x)s+=c[x];
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)read(a[i].s1),read(a[i].s2);
	for(int i=1;i<=m;++i)read(b[i].s1),read(b[i].s2);
//	for(int i=14;i<=14;++i)cout<<b[i].s1<<' '<<b[i].s2<<endl;
	if(o){
		for(int i=1;i<=n;++i)V=max(V,(int)a[i].s1.size());
		for(int i=1;i<=m;++i)
			if(b[i].s1.size()==b[i].s2.size())V=max(V,(int)b[i].s1.size());
		for(int i=1;i<=n;++i){
			int x,y,sz=a[i].s1.size();
			for(int j=0;j<sz;++j)
				if(a[i].s1[j]=='b'){
					x=j;
					break;
				}
			for(int j=0;j<sz;++j)
				if(a[i].s2[j]=='b'){
					y=j;
					break;
				}
			NODE nd=NODE{min(x,y),sz-max(x,y),0};
			s[x-y+V].emplace_back(nd);
//			if(x-y==-21)cout<<"  "<<i<<' '<<x-y<<' '<<nd.x<<' '<<nd.y<<' '<<nd.id<<endl;
		}
//		puts("");
		for(int i=1;i<=m;++i){
			int x,y,sz=b[i].s1.size();
			if(b[i].s2.size()!=sz)continue;
			for(int j=0;j<sz;++j)
				if(b[i].s1[j]=='b'){
					x=j;
					break;
				}
			for(int j=0;j<sz;++j)
				if(b[i].s2[j]=='b'){
					y=j;
					break;
				}
			NODE nd=NODE{min(x,y),sz-max(x,y),i};
			s[x-y+V].emplace_back(nd);
//			if(i==14)cout<<"  "<<x-y<<' '<<nd.x<<' '<<nd.y<<' '<<nd.id<<endl;
		}
		for(int k=1;k<=V*2;++k){
			if(!s[k].size())continue;
			sort(s[k].begin(),s[k].end(),[](NODE x,NODE y){return x.x==y.x?x.y<y.y:x.x<y.x;});
			for(NODE i:s[k])
				if(i.id)ans[i.id]+=query(i.y);
				else update(i.y,1);
			for(NODE i:s[k])
				if(!i.id)update(i.y,-1);
		}
		for(int i=1;i<=m;++i)printf("%d\n",ans[i]);
	}
	return 0;
}

/*
5 5
ab ba
aaba aaab
abaa aaab
baa aba
baaaa aaaba

aabaaa abaaaa
aaabaaa aaaaaba
aab baa
aba aab
abaaaa aaaaba

1
1
0
0
1
*/
