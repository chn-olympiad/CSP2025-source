#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int T,n;
struct node{
	int a,b,c;
}s[N],p1[N],p2[N],p3[N];
int sum[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0,c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			int maxn=max(s[i].a,max(s[i].b,s[i].c));
			ans+=maxn;
			if(maxn==s[i].a) p1[++c1]=s[i];
			else if(maxn==s[i].b) p2[++c2]=s[i];
			else if(maxn==s[i].c) p3[++c3]=s[i];
		}
		if(c1>n/2){
			for(int i=1;i<=c1;i++) sum[i]=max(p1[i].b-p1[i].a,p1[i].c-p1[i].a);
			sort(sum+1,sum+1+c1,cmp);
			for(int i=1;i<=c1-n/2;i++) ans+=sum[i];
		}
		if(c2>n/2){
			for(int i=1;i<=c2;i++) sum[i]=max(p2[i].a-p2[i].b,p2[i].c-p2[i].b);
			sort(sum+1,sum+1+c2,cmp);
			for(int i=1;i<=c2-(n/2);i++) ans+=sum[i];
		}
		if(c3>n/2){
			for(int i=1;i<=c3;i++) sum[i]=max(p3[i].a-p3[i].c,p3[i].b-p3[i].c);
			sort(sum+1,sum+1+c3,cmp);
			for(int i=1;i<=c3-n/2;i++) ans+=sum[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
