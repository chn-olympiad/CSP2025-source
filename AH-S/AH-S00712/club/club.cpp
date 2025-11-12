#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int x[5][N];
int c1=0,c2=0,c3=0,n=0;
int sum=0,q[N];
bool cmp(int x,int y){
	return x>y;
	}
void f(int p,int pp){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(x[p][i]==max(x[1][i],max(x[2][i],x[3][i]))){
			q[++cnt]=x[1][i]+x[2][i]+x[3][i]-min(x[1][i],min(x[2][i],x[3][i]))-2*x[p][i];
		}
	}
	sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<=pp-n/2;i++)sum+=q[i];
}
void clean(){
	memset(x[1],0,sizeof(x[1]));
	memset(x[2],0,sizeof(x[2]));
	memset(x[3],0,sizeof(x[3]));
	memset(q,0,sizeof(q));
	c1=c2=c3=sum=n=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		clean();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",x[1]+i,x[2]+i,x[3]+i);
			if(x[1][i]==max(x[1][i],max(x[2][i],x[3][i]))){
				c1++;
				sum+=x[1][i];
			}else if(x[2][i]==max(x[1][i],max(x[2][i],x[3][i]))){
				c2++;
				sum+=x[2][i];
			}else{
				c3++;
				sum+=x[3][i];
			}
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			printf("%d\n",sum);
			continue;
		}
		if(c1>n/2)f(1,c1);
		else if(c2>n/2)f(2,c2);
		else f(3,c3);
		printf("%d\n",sum);
	}
	return 0;
}
