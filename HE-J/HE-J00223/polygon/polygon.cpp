#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int MOD=998244353;
int n,l[N],b[N];
long long ans=0;
void dfs(int ji,int k,int hou){
	if(k==ji+1){
		int sum=0,ma=-1e9;
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				sum+=l[i];
				ma=max(ma,l[i]);
			}
		}
		if(sum>ma*2){
		   ans++;
		   ans%=MOD;
	    }
		return ;
	}
	for(int i=hou;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(ji,k+1,i+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&l[i]);
	}
	for(int i=3;i<=n;i++){
		dfs(i,1,1);
	}
	printf("%lld\n",ans);
    return 0; 
} 
