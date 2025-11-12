#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=4e5+10,N=5e6+10;
int n,m,pn,t1,t2,ch[2][N][26],tot[2],id1[N],id2[N];bool bo[M];
ll vp1[M],vp2[M];
char s1[N],s2[N],s[N];
pair<ll,ll> b[M];
map<int,int> mp[M];
int inst(int o,int len){
	int rt=0;
	for(int i=1;i<=len;i++){
		if(!ch[o][rt][s[i]-'a'])ch[o][rt][s[i]-'a']=++tot[o];
		rt=ch[o][rt][s[i]-'a'];
	}
	return rt;
}
vector<int> g[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		int l=1,r=len;
		while(l<=len&&s1[l]==s2[l])l++;
		while(r>=1&&s1[r]==s2[r])r--;
		if(l>r)continue;
		int tn=0;
		for(int j=r;j>=1;j--)s[++tn]=s1[j];
		int rt1=inst(0,tn);
		tn=0;
		for(int j=r;j>=1;j--)s[++tn]=s2[j];
		int rt2=inst(0,tn);
		tn=0;
		for(int j=l;j<=len;j++)s[++tn]=s1[j];
		int rt3=inst(1,tn);
		tn=0;
		for(int j=l;j<=len;j++)s[++tn]=s2[j];
		int rt4=inst(1,tn);
		ll r1=1ll*rt1*N+rt2,r2=1ll*rt3*N+rt4;
		vp1[++t1]=r1;vp2[++t2]=r2;
		b[++pn]={r1,r2};
	}
	sort(vp1+1,vp1+t1+1);
	sort(vp2+1,vp2+t2+1);
	t1=unique(vp1+1,vp1+t1+1)-vp1-1;
	t2=unique(vp2+1,vp2+t2+1)-vp2-1;
	for(int i=1;i<=pn;i++){
		b[i].first=lower_bound(vp1+1,vp1+t1+1,b[i].first)-vp1;
		b[i].second=lower_bound(vp2+1,vp2+t2+1,b[i].second)-vp2;
		mp[b[i].first][b[i].second]++;
		g[b[i].first].push_back(b[i].second);
	}
	sort(b+1,b+pn+1);
	for(int i=1;i<=m;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		if(len!=strlen(s2+1)){
			puts("0");
			continue;
		}
		int l=1,r=len;
		while(l<=len&&s1[l]==s2[l])l++;
		while(r>=1&&s1[r]==s2[r])r--;
		int rt1=0,rt2=0,p1=0,p2=0;
		for(int j=r;j>=1;j--){
			int v1=s1[j]-'a',v2=s2[j]-'a';
			if(!ch[0][rt1][v1]||!ch[0][rt2][v2])break;
			rt1=ch[0][rt1][v1];rt2=ch[0][rt2][v2];
			if(j>l)continue;
			ll r1=1ll*rt1*N+rt2;
			int x=lower_bound(vp1+1,vp1+t1+1,r1)-vp1;
			if(vp1[x]==r1)id1[++p1]=x;
		}
		int rt3=0,rt4=0;
		for(int j=l;j<=len;j++){
			int v1=s1[j]-'a',v2=s2[j]-'a';
			if(!ch[1][rt3][v1]||!ch[1][rt4][v2])break;
			rt3=ch[1][rt3][v1];rt4=ch[1][rt4][v2];
			if(j<r)continue;
			ll r2=1ll*rt3*N+rt4;
			int x=lower_bound(vp2+1,vp2+t2+1,r2)-vp2;
			if(vp2[x]==r2)id2[++p2]=x,bo[x]=1;
		}
		int ans=0;
		for(int j=1;j<=p1;j++){
			if(m==1||p2*10>g[id1[j]].size()){
				for(int k:g[id1[j]])if(bo[k])ans++;
			}
			else for(int k=1;k<=p2;k++)ans+=mp[id1[j]][id2[k]];
		}
		for(int j=1;j<=p2;j++)bo[id2[j]]=0;
		printf("%d\n",ans);
	}
}