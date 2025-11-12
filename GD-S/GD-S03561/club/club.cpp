#include<bits/stdc++.h>
using namespace std;
int T;
struct Edge{
	int ai,bi,ci;
};
int a,b,c;
Edge no[100005]; 
int n;
long long f[100005];
bool cmp1(Edge a,Edge b){
	if(a.ai>b.ai){
		return true;
	}
	return false;
}
bool cmp2(Edge a,Edge b){
	if(a.bi>b.bi){
		return true;
	}
	return false;
}
bool cmp3(Edge a,Edge b){
	if(a.ci>b.ci){
		return true;
	}
	return false;
}
int dfs(int x){
	while(a<=n/2&&b<=n/2&&c<=n/2){
		f[x]=max(dfs(x-1)+no[x].ai,max(dfs(x-1)+no[x].bi,dfs(x-1)+no[x].ci));
		if(f[x]=f[x-1]+no[x].ai){
			a++;
		}else if(dfs(x-1)+no[x].bi){
			b++;
		}else{
			c++;
		}
		return f[x];
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		a=0;
		b=0;
		c=0;
		memset(no,0,sizeof(no));
		memset(f,0,sizeof(f));
		int f1=0,f2=0,f3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&no[i].ai,&no[i].bi,&no[i].ci);
			if(no[i].ai!=0){
				f1=1;
			}
			if(no[i].bi!=0){
				f2=1;
			}
			if(no[i].ci!=0){
				f3=1;
			}
		}
		if(f2==0&&f3==0){
			sort(no+1,no+1+n,cmp1);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=no[i].ai;
			}
			printf("%d\n",sum);
			continue;
		}
		if(f1==0&&f3==0){
			sort(no+1,no+1+n,cmp2);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=no[i].bi;
			}
			printf("%d\n",sum);
			continue;
		}
		if(f2==0&&f1==0){
			sort(no+1,no+1+n,cmp3);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=no[i].ci;
			}
			printf("%d\n",sum);
			continue;
		}
		if(n==2){
			int sum;
			sum=max(no[1].ai+no[2].bi,max(no[1].ai+no[2].ci,max(no[1].bi+no[2].ai,max(no[1].bi+no[2].ci,max(no[1].ci+no[2].bi,no[1].ci+no[2].ai)))));
			printf("%d\n",sum);
			continue;
		}
		if(n==4){
			int sum;
			sum=max(max(no[1].bi+no[2].ci+no[3].ai+no[4].ai,no[1].ci+no[2].bi+no[3].ai+no[4].ai),max(max(no[1].bi+no[2].ai+no[3].ci+no[4].ai,no[1].ci+no[2].ai+no[3].bi+no[4].ai),max(max(max(no[1].ai+no[2].ai+no[3].bi+no[4].ci,no[1].ai+no[2].ai+no[3].ci+no[4].bi),max(no[1].ai+no[2].bi+no[3].ai+no[4].ci,no[1].ai+no[2].ci+no[3].ai+no[4].bi)),max(max(no[1].ai+no[2].bi+no[3].ci+no[4].ai,no[1].ai+no[2].ci+no[3].bi+no[4].ai),max(no[1].bi+no[2].ai+no[3].ai+no[4].ci,no[1].ci+no[2].ai+no[3].ai+no[4].bi)))));					
			printf("%d\n",sum);
			continue;
		}
		printf("%d\n",dfs(n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
