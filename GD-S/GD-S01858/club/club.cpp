#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100005;
int t,n,h1=1,r1,h2=1,r2,h3=1,r3;
LL ans;

int a1[N],a2[N],a3[N];
int q1[N],q2[N],q3[N];

bool cmp1(int x,int y){
	if(a2[x]!=a2[y]){
		if(a3[y]>a2[x]&&a3[y]>a3[x])
			return a3[x]<a3[y];
		else return a2[x]<a2[y];
	}else if(a3[x]!=a3[y])
		return a3[x]<a3[y];
	else
		return a1[x]>a1[y];
}

bool cmp2(int x,int y){
	if(a1[x]!=a1[y]){
		if(a3[y]>a1[x]&&a3[y]>a3[x])
			return a3[x]<a3[y];
		else return a1[x]<a1[y];
	}else if(a3[x]!=a3[y])
		return a3[x]<a3[y];
	else
		return a2[x]>a2[y];
}

bool cmp3(int x,int y){
	if(a1[x]!=a1[y]){
		if(a2[y]>a1[x]&&a2[y]>a2[x])
			return a2[x]<a2[y];
		else return a1[x]<a1[y];
	}else if(a2[x]!=a2[y])
		return a2[x]<a2[y];
	else
		return a3[x]>a3[y];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		//多测清空
		ans=0;
		h1=1,h2=1,h3=1;
		r1=0,r2=0,r3=0; 
		
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			// 选出最大 
			a1[i]=u,a2[i]=v,a3[i]=w;
			if(u>=v&&u>=w)
				q1[++r1]=i;
			if(v>=u&&v>=w)
				q2[++r2]=i;
			if(w>=u&&w>=v)
				q3[++r3]=i;
		}
		
		//不存在两列爆满情况 
		if(r1>n/2){
			sort(q1+1,q1+1+r1,cmp1);
			
			while(r1>n/2){
				int t=q1[r1];
				if(a2[t]>=a3[t]){
					q2[++r2]=t;
					--r1;
				}else{
					q3[++r3]=t;
					--r1;
				}
			}
		}
		
		if(r2>n/2){
			sort(q2+1,q2+1+r2,cmp2);
			
			while(r2>n/2){
				int t=q2[r2];
				if(a1[t]>=a3[t]){
					q1[++r1]=t;
					--r2;
				}else{
					q3[++r3]=t;
					--r2;
				}
			}
		}
		
		if(r3>n/2){
			sort(q3+1,q3+1+r3,cmp3);
			
			while(r3>n/2){
				int t=q3[r3];
				if(a1[t]>=a2[t]){
					q1[++r1]=t;
					--r3;
				}else{
					q2[++r2]=t;
					--r3;
				}
			}
		}
		
		while(h1<=r1){
			ans+=a1[q1[h1]];
			h1++;
		}
		while(h2<=r2){
			ans+=a2[q2[h2]];
			h2++;
		}
		while(h3<=r3){
			ans+=a3[q3[h3]];
			h3++;
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
