#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int b=29;
const int p=998244353;
map<pair<int,int>,int>id;
map<int,int>mp;
int n,q,x,y;
int ans[N],cnt;
int val[N];
string vx,vy;
struct node{
	string x;
	string y;
	int op;
}d; 
int cmp(const node &a,const node &b){
	return a.x<b.x||(a.x==b.x&&a.op<b.op);
} 
void find(string sx,string sy){
	int l,r,sz=sx.size();
	for(int i=sz-1;i>=0;i--)
	if(sx[i]!=sy[i])
	l=i;
	for(int i=0;i<sz;i++)
	if(sx[i]!=sy[i]) 
	r=i;
	vx="";vy="";
	for(int i=l-1;i>=0;i--)
	vx+=sx[i];
	for(int i=r+1;i<sz;i++)
	vy+=sx[i];
	x=0;y=0;
	for(int i=l;i<=r;i++)
	x=x*b+sx[i]-'a'+1,x%=p;
	for(int i=l;i<=r;i++)
	y=y*b+sy[i]-'a'+1,y%=p;
}
vector<node>vis[N];
vector<int>pq[N];
string read(){
	string s="";
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c>='a'&&c<='z')s+=c,c=getchar();
	return s;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string sx=read();
		string sy=read();
		if(sx==sy)continue;
		find(sx,sy);
		int vp=id[make_pair(x,y)];
		if(!vp)vp=id[make_pair(x,y)]=++cnt;
		d.x=vx;d.y=vy;d.op=0;
		vis[vp].push_back(d);
	}
	for(int i=1;i<=q;i++){
		string sx=read();
		string sy=read();
		find(sx,sy);
		int vp=id[make_pair(x,y)];
		if(!vp)continue;
		d.x=vx;d.y=vy;d.op=i;
		vis[vp].push_back(d);
	}
	for(int i=1;i<=cnt;i++){
		sort(vis[i].begin(),vis[i].end(),cmp);
		int pre=0;mp.clear();
		for(int j=0;j<vis[i].size();j++){
			string sx=vis[i][j].x;
			string sy=vis[i][j].y;
			if(!sx.size())pre=j+1;
			else {
				pq[j].clear();
				for(int k=0;k<sx.size();k++)
				pq[j].push_back(k?(pq[j][k-1]*b+sx[k]-'a'+1)%p:sx[k]-'a'+1);
				int sp=pq[pre].size();
				int sz=pq[j].size();
				while(sp>sz||pq[j][sp-1]!=pq[pre][sp-1]){
					if(!vis[i][pre].op)
					mp[val[pre]]--;
					pre++;
					sp=pq[pre].size();
				}
			}
			if(!vis[i][j].op){
				val[j]=0;
				for(int k=0;k<sy.size();k++)
				val[j]=val[j]*b+sy[k]-'a'+1,val[j]%=p;
				mp[val[j]]++;
				continue;
			}
			val[j]=0;ans[vis[i][j].op]+=mp[0];
			for(int k=0;k<sy.size();k++){
				val[j]=val[j]*b+sy[k]-'a'+1,val[j]%=p;
				ans[vis[i][j].op]+=mp[val[j]];
			}
		}
	}
	for(int i=1;i<=q;i++)
	printf("%lld\n",ans[i]);
	return 0;
}
