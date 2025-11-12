#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000000  
int n,q;
int base=131;
map<pair<unsigned long long,unsigned long long>,int> vis;
map<unsigned long long,int> vis1;
map<pair<int,int>,int> vis3;
unsigned long long b[MAXN+5],c[MAXN+5],h[MAXN+5];
struct node{
	int now,pre;
	int len,cnt;
};
vector<node> G[MAXN+5];
int cnt[MAXN+5],vis2[MAXN+5];
bool cmp(node u,node v){
	return u.len<v.len;
}
bool cmp1(node u,node v){
	return u.now<v.now;
}
unsigned long long calc_b(int x,int y){
	return b[y]-b[x-1]*h[y-x+1];
}
unsigned long long calc_c(int x,int y){
	return c[y]-c[x-1]*h[y-x+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	h[0]=1;
	for(int i=1;i<=MAXN;i++) h[i]=h[i-1]*base;
	scanf("%d%d",&n,&q);
	string s,t;
	int tot=0;
	vis1[0]=1;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int len=s.size(),tot1=1;
		unsigned long long sum1=0,sum2=0;
		int x=len+1;
		for(int j=len;j>=1;j--){
			if(s[j-1]==t[j-1]) x=j;
			else break; 
		}
		b[0]=c[0]=1;
		for(int j=1;j<=len;j++){
			b[j]=b[j-1]*base+s[j-1]-'a'+1;
			c[j]=c[j-1]*base+t[j-1]-'a'+1;
		}
		for(int j=1;j<=len;j++){
			sum1=sum1*base+s[j-1]-'a'+1;
			sum2=sum2*base+t[j-1]-'a'+1;
			if(j==x-1){
				int ret=vis[{sum1,sum2}];
				if(!ret) vis[{sum1,sum2}]=++tot,ret=tot;
				int lst=0;
				for(int k=j;k<=len;k++){
					unsigned long long now=calc_b(j+1,k);
					int ret1=vis1[now];
					if(!ret1) vis1[now]=++tot1,ret1=tot1;
					int y=0;
					if(k==len) y=1;
					if(!vis3[{ret,ret1}]){
						vis3[{ret,ret1}]=1;
						G[ret].push_back({ret1,lst,k-j,y});
					}
					vis3[{ret,ret1}]+=y;
					lst=ret1;
				}
			}
		}
	}
	for(int i=1;i<=tot;i++) sort(G[i].begin(),G[i].end(),cmp);
	for(int i=1;i<=tot;i++)
		for(int j=0;j<G[i].size();j++)
			if(G[i][j].now!=1)vis3[{i,G[i][j].now}]+=vis3[{i,G[i][j].pre}]-1;
	//cout<<vis3[{1,2}]<<' '<<vis3[{1,1}]<<endl; 
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		int len=s.size(),mn=INT_MAX,mx=INT_MIN;
		for(int j=1;j<=len;j++){
			if(s[j-1]!=t[j-1]){
				mn=min(mn,j);
				mx=max(mx,j);
			}
		}
		int len1=mx-mn+1;
		b[0]=c[0]=1;
		for(int j=1;j<=len;j++){
			b[j]=b[j-1]*base+s[j-1]-'a'+1;
			c[j]=c[j-1]*base+t[j-1]-'a'+1;
		}
		for(int j=mx;j<=len;j++){
			unsigned long long ret=calc_b(mx+1,j);
			if(!vis1[ret]) vis2[j]=0;
			else vis2[j]=vis1[ret];
		}
		int ans=0;
		for(int j=mn;j>=1;j--){
			unsigned long long val1=calc_b(j,mx),val2=calc_c(j,mx);
			int ret=vis[{val1,val2}];
			if(!ret) continue;
			int l=mx,r=len;
			while(l<=r){
				int mid=(l+r)>>1;
				if(vis2[mid]==0||!vis3[{ret,vis2[mid]}]) r=mid-1;
				else l=mid+1;
			}
			if(vis3[{ret,vis2[r]}])ans+=vis3[{ret,vis2[r]}]-1;
		}
		printf("%d\n",ans);
	}
} 
