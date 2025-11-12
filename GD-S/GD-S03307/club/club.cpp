#include<bits/stdc++.h>
using namespace std;
struct dian{
	int a,b,c;
	const bool operator<(dian&l){
		return max(a,max(b,c))<max(l.a,max(l.b,l.c));
	}
}ren[100010];
int n;
inline const int dfs(int i,int a,int b,int c){
	return i==n?0:a==n>>1?max(dfs(i+1,a,b+1,c)+ren[i].b,dfs(i+1,a,b,c+1)+ren[i].c):b==n>>1?max(dfs(i+1,a+1,b,c)+ren[i].a,dfs(i+1,a,b,c+1)+ren[i].c):c==n>>1?max(dfs(i+1,a,b+1,c)+ren[i].b,dfs(i+1,a+1,b,c)+ren[i].a):max(dfs(i+1,a+1,b,c)+ren[i].a,max(dfs(i+1,a,b+1,c)+ren[i].b,dfs(i+1,a,b,c+1)+ren[i].c));
}
int main(){
	int a,b,c,m,t,a1,b1,c1;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i1=0;i1<t;i1++){
		scanf("%d",&n);
		a=b=c=a1=b1=c1=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ren[i].a,&ren[i].b,&ren[i].c);
		}
		printf("%d\n",dfs(0,0,0,0));
	}
	return 0;
} 
/*
#include<bits/stdc++.h>
using namespace std;
struct dian{
	int a,b,c;
	const bool operator<(dian&l){
		return max(a,max(b,c))<max(l.a,max(l.b,l.c));
	}
}ren[100010];
bool cmpbc(dian&l,dian&r){
	return max(r.b,r.c)<max(l.b,l.c);
}
bool cmpac(dian&l,dian&r){
	return max(r.a,r.c)<max(l.a,l.c);
}
bool cmpab(dian&l,dian&r){
	return max(r.b,r.a)<max(l.b,l.a);
}
bool cmpa(dian&l,dian&r){
	return r.a<l.a;
}
bool cmpb(dian&l,dian&r){
	return r.b<l.b;
}
bool cmpc(dian&l,dian&r){
	return r.c<l.c;
}
int main(){
	int a,b,c,n,m,t,a1,b1,c1;
	//freopen(stdin,"club.in","r");
	//freopen(stdout,"club.out","w");
	scanf("%d",&t);
	for(int i1=0;i1<t;i1++){
		scanf("%d",&n);
		a=b=c=a1=b1=c1=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ren[i].a,&ren[i].b,&ren[i].c);
		}
		sort(ren,ren+n);
		for(int i=n-1;i>=0;i--){
			if(max(ren[i].a,max(ren[i].b,ren[i].c))==ren[i].a){
				a++;
				a1+=ren[i].a;
			}else if(max(ren[i].a,max(ren[i].b,ren[i].c))==ren[i].b){
					b++;
					a1+=ren[i].b;
			}else if(max(ren[i].a,max(ren[i].b,ren[i].c))==ren[i].c){
					c++;
					a1+=ren[i].c;
			}
			if(a==(n>>1)){
				sort(ren,ren+n-a-b-c,cmpbc);
				break;
			}
			if(b==(n>>1)){
				sort(ren,ren+n-a-b-c,cmpac);
				break;
			}
			if(c==(n>>1)){
				sort(ren,ren+n-a-b-c,cmpab);
				break;
			}
		}
		for(int i=n-a-b-c-1;i>=0;i--){
			if(max(a==n>>1?-1:ren[i].a,max(b==n>>1?-1:ren[i].b,c==n>>1?-1:ren[i].c))==ren[i].a){
				a++;
				a1+=ren[i].a;
			}else if(max(a==n>>1?-1:ren[i].a,max(b==n>>1?-1:ren[i].b,c==n>>1?-1:ren[i].c))==ren[i].b){
					b++;
					a1+=ren[i].b;
			}else if(max(a==n>>1?-1:ren[i].a,max(b==n>>1?-1:ren[i].b,c==n>>1?-1:ren[i].c))==ren[i].c){
					c++;
					a1+=ren[i].c;
			}
		}
		printf("%d\n",a1);
	}
	return 0;
} 
*/
