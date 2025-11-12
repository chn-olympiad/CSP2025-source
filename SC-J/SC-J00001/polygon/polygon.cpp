#include<bits/stdc++.h>
using namespace std;
int n,a[6000],ans,f,choose[100];
bool flao=true;
int po=4,pt=7;
void dfs(int u,int h,int sum,int k,int c){
	if(k==n+1){
		if(u==c){
			f++;
		}
		if(sum>2*h&&u==c){			
			ans++;
			ans%=998244353;
		}
		return ;
	}else{
		if(u>c){
			choose[c+1]=k;
			dfs(u,max(h,a[k]),sum+a[k],k+1,c+1);
		}
		choose[c+1]=0;
		dfs(u,h,sum,k+1,c);
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flao=false;
		}
	}
	if(flao){
		f=1;
		for(int i=1;i<=n-3;i++){
			f+=po;
			f%=998244353;
			po+=pt;
			po%=998244353;
			pt=pt*2+1;
			pt%=998244353;
		}
		printf("%d ",f);
		return 0; 
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,0,1,0);
	}
	printf("%d",ans);
	return 0;
}