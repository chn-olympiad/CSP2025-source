#include<bits/stdc++.h>

using namespace std;
int n,ans;
struct node{int val[3],id,rk[3],p[3];} a[100010];
struct csp{int val,c,id;};
bool operator >(const csp& A,const csp& B){return A.c>B.c;}
		priority_queue<csp ,vector<csp> ,greater<csp> >q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) {
			a[i].id=i;
			for(int j=0;j<3;++j) scanf("%d",&a[i].val[j]);
		}
		for(int i=0;i<3;++i)
			while(!q[i].empty()) q[i].pop(); 
		for(int i=1;i<=n;++i){
			int x=0,maxn=a[i].val[0];
			if(maxn<a[i].val[1]) maxn=a[i].val[1],x=1;
			if(maxn<a[i].val[2]) maxn=a[i].val[2],x=2;
			ans+=maxn;
			a[i].rk[x]=0;int f1=0,f2=1;
			if(x==0) f1=2;
			else if(x==1) f2=2;
			
			if(a[i].val[f1]<a[i].val[f2]) a[i].rk[f2]=1,a[i].rk[f1]=2;
			else a[i].rk[f1]=1,a[i].rk[f2]=2;
			
			for(int j=0;j<3;++j) a[i].p[a[i].rk[j]]=j;
			q[x].push(csp{maxn,maxn-a[i].val[a[i].p[1]],i});
		}
			for(int i=0;i<2;++i)
				while(q[i].size()>n/2){
					csp now=q[i].top();
					int x=now.id,y=now.val,c=now.c;
					q[i].pop();
					ans-=c;
					int z= a[x].p[a[x].rk[i]+1 ];
					y=a[x].val[z];
					now.val=y;
					q[z].push(now);
			 	}
		printf("%d\n",ans);
	}

	
	return 0;
} 
