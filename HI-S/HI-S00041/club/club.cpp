#include<bits/stdc++.h>
using namespace std;
int t;
int sum=0;
struct jgt{
	int a,b,c;
}f[100005];
bool cmp(jgt u,jgt v){
	return u.c>v.c;
}
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&f[j].a,&f[j].b,&f[j].c);	
		}
		sort(f+1,f+n+1,cmp);
		for(int j=1;j<=n;j+=2){
			sum=sum+max(f[j].a+f[j+1].b,max(f[j].a+f[j+1].c,max(f[j].b+f[j+1].a,max(f[j].b+f[j+1].c,max(f[j].c+f[j+1].a,f[j].c+f[j+1].b)))));
		}
		printf("%d\n",sum);
		sum=0;
	}

	return 0;
}

