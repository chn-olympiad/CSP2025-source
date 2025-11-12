#include<bits/stdc++.h>  
using namespace std;
const int N=5020,MOD=998244353;
int n,a[N],sum,ans,b[N],spe[N];
struct data{
	int val,id;
	bool operator < (data other)const{
		return val<other.val;
	}
};
priority_queue<data>pq;
void dfs(int p,int s){
	if(p==0){
		while((!pq.empty())&&b[pq.top().id]==1){
			pq.pop();
		}
		if(sum>2*pq.top().val){
			ans=(ans+1)%MOD;
		}
		return; 
	} 
	for(int i=s;i<=n;i++){
		pq.push({a[i],i});
		b[i]=0;
		sum+=a[i];
		dfs(p-1,i+1);
		b[i]=1;
		sum-=a[i];
	}
}
bool flg;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flg=true;
		}
	}
	if(!flg){
		spe[3]=1;
		for(int i=4;i<=n;i++){
			spe[i]=((spe[i-1]*2)+(((i-2)*(i-1))/2))%MOD;
		}
		printf("%d",spe[n]%MOD);
		exit(0);
	}
	for(int i=3;i<=n;i++){
		sum=0;
		dfs(i,1);
		while(!pq.empty()){
			pq.pop();
		}
	}
	printf("%d",ans);
	return 0;
}
