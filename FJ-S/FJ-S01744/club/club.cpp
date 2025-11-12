#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

struct Node{
	int a,b,c;
}p[N];

int cal(Node x){
	if(x.a>=x.b && x.a>=x.c)
		return x.a-max(x.b,x.c);
	if(x.b>=x.a && x.b>=x.c)
		return x.b-max(x.a,x.c);
	if(x.c>=x.a && x.c>=x.b)
		return x.c-max(x.a,x.b);
}

bool cmp(Node x,Node y){
	return cal(x)>cal(y);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,ans=0,da=0,db=0,dc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(p[i].a>=p[i].b && p[i].a>=p[i].c){
				if((da+1)*2<=n)
					da++,ans+=p[i].a;
				else
					ans+=max(p[i].b,p[i].c);
			}else if(p[i].b>=p[i].a && p[i].b>=p[i].c){
				if((db+1)*2<=n)
					db++,ans+=p[i].b;
				else
					ans+=max(p[i].a,p[i].c);
			}else{
				if((dc+1)*2<=n)
					dc++,ans+=p[i].c;
				else
					ans+=max(p[i].a,p[i].b);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
