#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,d;
}ti[200001];
int cmp(node x,node y){
	return x.d>y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&ti[i].a,&ti[i].b,&ti[i].c); 	
	ti[i].d=max(ti[i].a,max(ti[i].b,ti[i].c))-(ti[i].a+ti[i].b+ti[i].c-max(ti[i].a,max(ti[i].b,ti[i].c))-min(ti[i].a,min(ti[i].b,ti[i].c))); 
		}
		long long sum=0;
		sort(ti+1,ti+n+1,cmp);
		int ag=0,bg=0,cg=0;
		for(int i=1;i<=n;i++){
			if(ti[i].a==max(ti[i].a,max(ti[i].b,ti[i].c))) {
			if(ag<n/2){
					ag++;
				sum+=ti[i].a;
				continue;
			}
			else if(ti[i].b==max(ti[i].b,ti[i].c)){
				bg++;
				sum+=ti[i].b;
				continue;
			}
			else{
				cg++;
				sum+=ti[i].c;
				continue;
			}
			}
		  	if(ti[i].b==max(ti[i].a,max(ti[i].b,ti[i].c))) {
			if(bg<n/2){
					bg++;
				sum+=ti[i].b;
				continue;
			}
			else if(ti[i].a==max(ti[i].a,ti[i].c)){
				ag++;
				sum+=ti[i].a;
				continue;
			}
			else{
				cg++;
				sum+=ti[i].c;
				continue;
			}
			}
			if(ti[i].c==max(ti[i].a,max(ti[i].b,ti[i].c))) {
			if(cg<n/2){
					cg++;
				sum+=ti[i].c;
				continue;
			}
			else if(ti[i].b==max(ti[i].b,ti[i].a)){
				bg++;
				sum+=ti[i].b;
				continue;
			}
			else{
				ag++;
				sum+=ti[i].a;
				continue;
			}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
