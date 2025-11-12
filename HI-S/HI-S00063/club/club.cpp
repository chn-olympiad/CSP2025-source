#include <bits/stdc++.h>

using namespace std;
int t,n;
long long ans;
int const maxN=100010;
struct node{
	int d[3];
}mem[maxN];
long long num[3],sum; 
long long res[maxN];
void dfs(int t){
	if(t>n){
		ans=max(ans,sum);		
//		for(int i=1;i<=n;i++){
//			printf("%d ",res[i]);
//		}
//		printf("\n");
		return;
	}
	for(int i=0;i<=2;i++){
		sum+=mem[t].d[i];
		num[i]++;
		res[t]=mem[t].d[i];
		if(num[i]>n/2){
			sum-=mem[t].d[i];
			num[i]--;
			res[t]=0;			
			continue;
		}else{
			dfs(t+1);
			sum-=mem[t].d[i];
			num[i]--;
			res[t]=0;
		}
	}
}
bool cmp1(node a,node b){
	return a.d[0]>b.d[0];
}
bool cmp2(node a,node b){
	return max(a.d[0],a.d[1])>max(b.d[0],b.d[1]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t); 
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&mem[i].d[0],&mem[i].d[1],&mem[i].d[2]);
		}
//		for(int i=1;i<=n;i++){
//			printf("%d %d %d\n",mem[i].d[0],mem[i].d[1],mem[i].d[2]);
//		}		
		ans=sum=0;//答案和累积清空 
		for(int i=0;i<=2;i++) num[i]=0;//部门清空 
		if(n<=10){
			//暴力
			dfs(1);
			printf("%lld\n",ans); 
		}else{
			int s1=0,s2=0;
			for(int i=1;i<=n;i++){
				if(mem[i].d[1]==0&&mem[i].d[2]==0){
					s1++;
				}
				if(mem[i].d[2]==0){
					s2++;
				}
			}
			
			if(s1==n){
				sort(mem+1,mem+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=mem[i].d[0];
				}
			}else if(s2==n){
				sort(mem+1,mem+1+n,cmp2);
				bool f1=0,f2=0;
				for(int i=1;i<=n;i++){
					if((mem[i].d[0]>=mem[i].d[1]||f2)&&!f2){
						ans+=mem[i].d[0];
						num[0]++;
					}else{
						ans+=mem[i].d[1];
						num[1]++;
					}
					if(num[0]==n/2) f1=1;
					if(num[1]==n/2) f2=1;
				} 
			}
			printf("%lld\n",ans);
		}
	} 
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
