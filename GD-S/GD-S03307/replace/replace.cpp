#include<bits/stdc++.h>
using namespace std;
struct dian{
	int a,b,c;
	const bool operator<(dian&l){
		return c<l.c;
	}
	const void operator=(const dian l){
		a=l.a;b=l.b;c=l.c;
	}
};
struct pr{
	int a,b;
};
int n,bj[10200],nc[15][10200],pl[15]={0,1,2,3,4,5,6,7,8,9,10,11},m;
bool vis[1000];
char cz[1000];
inline const long long dfs(int a,int b){
	if(n-a<m-b)return 0;
	//printf("½øÈë%d %d\n",a,b);
	if(a==n-1){
		for(int i=0;i<n;i++){
			if(!vis[i]&&b+(cz[a]!=0&&bj[i]>a-b?1:0)>=m)return 1;
		}
		return 0;
	}
	long long sum=0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			//printf("Ñ¡Ôñ%d\n",i);
			vis[i]=1;
			if(cz[a]=='0'){
				sum=(sum+dfs(a+1,b))%998244353;
			}else if(cz[a]=='1'){
				sum=(sum+dfs(a+1,b+(bj[i]>a-b?1:0)))%998244353;
			}
			vis[i]=0;
		}
	}
	return sum;
}

int main(){
	int a,b,c,t,a1,b1,c1;
	long long sum=0,sum1=0,sum2=10000000000000000LL;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	a=b=c=a1=b1=c1=0;
	for(int i=0;i<m;i++)printf("0\n");
	return 0;
} 
