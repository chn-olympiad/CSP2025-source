#include<bits/stdc++.h>
using namespace std;
int n,t;
struct mu{
	int a,b,c;
} p[100005];
bool alla=1,olyab=1;
bool cmp(mu d,mu e){
	if(d.a==e.a)return d.b>e.b;
	return d.a>e.a
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int cna=0,cnb=0,cnc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
			if(alla&&(p[i].b!=0||p[i].c!=0))alla=0;
			if(olyab&&p[i].c!=0)olyab=0;
		}
		sort(p+1,p+n+1,cmp);
		if(alla){
			int js=0,ans=0;
			for(int i=1;i<=n;i++){
				if(i>n/2)js=1;
				if(js==0){
					ans+=p[i].a;
				}else{
					ans+=p[i].b;
				}
			}
			printf("%d",ans);
		}else if(olyab){
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

