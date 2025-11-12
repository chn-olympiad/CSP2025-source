#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,dp[N],a[9],sum,o;
struct node{
	int a,s,d,num,f;
}s[N];
bool cmp(node x,node y){
	return x.f>y.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(a));
		sum=0,o=0,n=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].s,&s[i].d);
			s[i].f=max(s[i].a,max(s[i].s,s[i].d));
			if(s[i].f==s[i].a) s[i].num+=4;
			if(s[i].f==s[i].s) s[i].num+=2;
			if(s[i].f==s[i].d) s[i].num+=3;
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].num<=4&&a[s[i].num]+1>n/2){
				o=s[i].num;
				break;
			}
			if(s[i].num<=4)
			a[s[i].num]++;
			sum+=s[i].f;
			s[i].a=-1;
			s[i].s=-1;
			s[i].d=-1;
			s[i].f=-1;
			s[i].num=-1;
		}
		if(o==0){
			printf("%d \n",sum);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i].num==o){
				if(o==4) s[i].a=-1;
				if(o==2) s[i].s=-1;
				if(o==3) s[i].d=-1;
				s[i].f=max(s[i].a,max(s[i].s,s[i].d));
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i].f!=-1) sum+=s[i].f;
		}
			printf("%d\n",sum);
	}
	return 0;
} 
