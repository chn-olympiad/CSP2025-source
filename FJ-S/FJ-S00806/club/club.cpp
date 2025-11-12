#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
	int vis;
//	int maxn;
//	int pos,apos;
//	bool operator<(const node o)const{
//		return max(max(o.a,o.b),o.c)<max(max(a,b),c);
//	}
}m[100001];
//int numa[100001];
//int numb[100001];
//int numc[100001];
int ans;
void dfs(int a,int b,int c,int total,int sum){
	if(total==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(m[i].vis==0){
			m[i].vis=1;
			if(a+1<=n/2) dfs(a+1,b,c,total+1,sum+m[i].a);
			if(b+1<=n/2) dfs(a,b+1,c,total+1,sum+m[i].b);
			if(c+1<=n/2) dfs(a,b,c+1,total+1,sum+m[i].c);
			m[i].vis=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=INT_MIN;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
		}
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
//		int ans=0;
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++){
//			scanf("%d%d%d",&m[i].a,&m[i].b,&m[i].c);
//			m[i].maxn=max(max(m[i].a,m[i].b),m[i].c);
//		}
//		sort(m+1,m+1+n);
//		int num[4]={0};
//		memset(numa,0,sizeof(numa));
//		memset(numb,0,sizeof(numb));
//		memset(numc,0,sizeof(numc));
//		int ii=0,jj=0,kk=0;
//		for(int i=1;i<=n;i++){
//			if(m[i].maxn==m[i].a){
//				m[i].pos=1;
//				num[1]++;
//				ans+=m[i].a;
//				numa[++ii]=i;
//				if(m[i].b>=m[i].c){
//					m[i].apos=2;
//				}
//				else{
//					m[i].apos=3;
//				}
//			}
//			else if(m[i].maxn==m[i].b){
//				m[i].pos=2;
//				num[2]++;
//				ans+=m[i].b;
//				numb[++jj]=i;
//				if(m[i].a>=m[i].c){
//					m[i].apos=1;
//				}
//				else{
//					m[i].apos=3;
//				}
//			}
//			else{
//				m[i].pos=3;
//				num[3]++;
//				ans+=m[i].c;
//				numc[++kk]=i;
//				if(m[i].a>=m[i].b){
//					m[i].apos=1;
//				}
//				else{
//					m[i].apos=2;
//				}
//			}
//		}
//		if(num[1]>n/2){
//			for(int i=n/2+1;i<=ii;i++){
////				numa[i]
//				ans-=m[numa[i]].a;
//				if(m[numa[i]].apos==2){
//					jj++;
//					ans+=m[numa[i]].b;
//				}
//				else{
//					kk++;
//					ans+=m[numa[i]].c;
//				}
//			}
//			ii-=n/2;
//		}
//		else if(num[2]>n/2){
//			for(int i=n/2+1;i<=jj;i++){
////				numb[i]
//				ans-=m[numb[i]].b;
//				if(m[numb[i]].apos==1){
//					ii++;
//					ans+=m[numb[i]].a;
//				}
//				else{
//					kk++;
//					ans+=m[numb[i]].c;
//				}
//			}
//			jj-=n/2;
//		}
//		else if(num[3]>n/2){
//			for(int i=n/2+1;i<=kk;i++){
////				numc[i]
//				ans-=m[numc[i]].c;
//				if(m[numc[i]].apos==1){
//					ii++;
//					ans+=m[numc[i]].a;
//				}
//				else{
//					jj++;
//					ans+=m[numc[i]].b;
//				}
//			}
//			kk-=n/2;
//		}
//		printf("%d\n",ans);

		
	}
	return 0;
}

