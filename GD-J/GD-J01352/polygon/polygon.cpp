#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,k[5005];
void dfs(int m,int sum,int xx){
	if(m>n+1)return;
	if(m>=3){
		int x[5005],kk=0,ff=1;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++)
			if(k[i])
				x[++kk]=a[i];
		for(int i=1;i<=kk;i++)
			if(x[i]>=sum-x[i]){
				ff=0;break;
			}
		ans+=ff;
	}
	for(int i=xx+1;i<=n;i++){
		if(!k[i]){
			k[i]=1;
			dfs(m+1,sum+a[i],i);
			k[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}//±©Á¦¹À·Ö24 
