#include<bits/stdc++.h>
using namespace std;
int n,T;
struct node{
	int num1,num2,num3;
	int ex1,ex2;
	int n1,n2,n3;
}mem[100010];
bool cmp(node a,node b){
	if(a.ex1!=b.ex1)return a.ex1>b.ex1;
	return a.ex2>b.ex2;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&mem[i].num1,&mem[i].num2,&mem[i].num3);
			mem[i].n1=max(mem[i].num1,max(mem[i].num2,mem[i].num3));
			mem[i].n2=min(mem[i].num1,max(mem[i].num2,mem[i].num3));
			mem[i].n3=min(mem[i].num1,min(mem[i].num2,mem[i].num3));
			mem[i].ex1=mem[i].n1-mem[i].n2;
			mem[i].ex2=mem[i].n2-mem[i].n3;
		}
		int x=n/2;
		sort(mem+1,mem+n+1,cmp);
		int sum1=0,sum2=0,sum3=0;
		for(int i=1;i<=n;++i){
			if(mem[i].n1==mem[i].num1){
				if(sum1<x){
					sum1++;
					ans+=mem[i].n1;
				}
				else{
					if(mem[i].n2==mem[i].num2){
						if(sum2<x){
							sum2++;
							ans+=mem[i].n2;
						}
						else{
							sum3++;
							ans+=mem[i].n3;
						}
					}
					else{
						if(sum3<x){
							sum3++;
							ans+=mem[i].n2;
						}
						else{
							sum2++;
							ans+=mem[i].n3;
						}
					}
				}
			}
			else if(mem[i].n1==mem[i].num2){
				if(sum2<x){
					sum2++;
					ans+=mem[i].n1;
				}
				else{
					if(mem[i].n2==mem[i].num1){
						if(sum1<x){
							sum1++;
							ans+=mem[i].n2;
						}
						else{
							sum3++;
							ans+=mem[i].n3;
						}
					}
					else{
						if(sum3<x){
							sum3++;
							ans+=mem[i].n2;
						}
						else{
							sum1++;
							ans+=mem[i].n3;
						}
					}
				}
			}
			else{
				if(sum3<x){
					sum3++;
					ans+=mem[i].n1;
				}
				else{
					if(mem[i].n2==mem[i].num2){
						if(sum2<x){
							sum2++;
							ans+=mem[i].n2;
						}
						else{
							sum1++;
							ans+=mem[i].n3;
						}
					}
					else{
						if(sum1<x){
							sum1++;
							ans+=mem[i].n2;
						}
						else{
							sum2++;
							ans+=mem[i].n3;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
