#include<bits/stdc++.h>
using namespace std;
int t,n,t1,d1[100001],t2,d2[100001],t3,d3[100001],f1,f2,f3;
long long s;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s=t1=t2=t3=0;
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		memset(d3,0,sizeof(d3));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&f1,&f2,&f3);
			if((f1>=f2)&&(f2>=f3))d1[++t1]=f1-f2,s+=f2;
			else if((f1>=f3)&&(f3>=f2))d1[++t1]=f1-f3,s+=f3;
			else if((f2>=f1)&&(f1>=f3))d2[++t2]=f2-f1,s+=f1;
			else if((f2>=f3)&&(f3>=f1))d2[++t2]=f2-f3,s+=f3;
			else if((f3>=f1)&&(f1>=f2))d3[++t3]=f3-f1,s+=f1;
			else if((f3>=f2)&&(f2>=f1))d3[++t3]=f3-f2,s+=f2;
		}
		sort(d1+1,d1+t1+1,cmp);
		sort(d2+1,d2+t2+1,cmp);
		sort(d3+1,d3+t3+1,cmp);
		for(int i=1;i<=n/2;i++)
		  s+=d1[i]+d2[i]+d3[i];
		printf("%lld\n",s);
	}
	return 0;
}
