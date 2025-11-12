#include<bits/stdc++.h>
using namespace std;
struct qwq{
	int a,b,c;
	int p;
}peo[100005];
int q11,q22,q33;
int cmp1(qwq x,qwq y){
	if(x.p==1&&y.p==1)	return x.a>y.a;
	return x.a==y.a;
}
int cmp2(qwq x,qwq y){
	if(x.p==2&&y.p==2)	return x.b>y.b;
	return x.b==y.b;
}
int cmp3(qwq x,qwq y){
	if(x.p==3&&y.p==3)	return x.c>y.c;
	return x.c==y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t--){
		int ans=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&peo[i].a,&peo[i].b,&peo[i].c)	;
			if(peo[i].a >=peo[i].b&&peo[i].a>=peo[i].c){
				peo[i].p=1;q11++;
			}else if(peo[i].b >peo[i].a&&peo[i].b>=peo[i].c){
				peo[i].p=2;q22++;
			}
			q33=n-q11-q22;
		}
		
		
			if(q11>=q22&&q11>=q33){
				sort(peo+1,peo+n+1,cmp1);
				if(2*q11>n){
					for(int j=1;2*j<=n;j++)ans+=peo[j].a;
					for(int j=n/2+1;j<=n;j++)ans+=max(peo[j].b,peo[j].c);    
				}else for(int j=1;j<=n;j++)ans+=max(peo[j].a,max(peo[j].b,peo[j].c));
			}else if(q22>=q11&&q22>=q33){
				sort(peo+1,peo+n+1,cmp2);
				if(2*q22>n){
					for(int j=1;2*j<=n;j++)ans+=peo[j].b;
					for(int j=n/2+1;j<=n;j++)ans+=max(peo[j].a,peo[j].c);    
				}else for(int j=1;j<=n;j++)ans+=max(peo[j].a,max(peo[j].b,peo[j].c));
			}else if(q33>=q11&&q33>=q22){
				sort(peo+1,peo+n+1,cmp3);
				if(2*q33>n){
					for(int j=1;2*j<=n;j++)ans+=peo[j].c;
					for(int j=n/2+1;j<=n;j++)ans+=max(peo[j].a,peo[j].b);    
				}else for(int j=1;j<=n;j++)ans+=max(peo[j].a,max(peo[j].b,peo[j].c));
				}cout<<ans;
					
  
}
}
