#include<bits/stdc++.h>
using namespace std;
char buf[1000005],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
int read(){
	int x=0,f=0;char c=gc();
	while(!isdigit(c))f|=(c=='-'),c=gc();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=gc();
	return f?-x:x;
}
int T,n,ans,a[100005][3],val[100005];
vector<int>p[3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		p[0].clear();p[1].clear();p[2].clear();
		ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				ans+=a[i][0];
				val[i]=max(a[i][1]-a[i][0],a[i][2]-a[i][0]);
				p[0].push_back(i);
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				ans+=a[i][1];
				val[i]=max(a[i][0]-a[i][1],a[i][2]-a[i][1]);
				p[1].push_back(i);
			}
			else{
				ans+=a[i][2];
				val[i]=max(a[i][0]-a[i][2],a[i][1]-a[i][2]);
				p[2].push_back(i);
			}
		}
		int maxs=max({p[0].size(),p[1].size(),p[2].size()});
		if(maxs<=n/2)printf("%d\n",ans);
		else{
			int op=-1;
			if(p[0].size()==maxs)op=0;
			else if(p[1].size()==maxs)op=1;
			else op=2;
			sort(p[op].begin(),p[op].end(),[&](int x,int y){return val[x]>val[y];});
			for(int i=0;i<maxs-n/2;i++)ans+=val[p[op][i]];
			printf("%d\n",ans);
		}
	}
	return 0;
}
