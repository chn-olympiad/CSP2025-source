#include<bits/stdc++.h>
using namespace std;
queue<int>pv[2200005];
int a[500005],pxor[500005];
int ans,n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	pv[0].push(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pxor[i]=pxor[i-1]^a[i];
		pv[pxor[i]].push(i);
	}
	int st=0; 
	for(int i=1;i<=n;i++){
		while(pv[pxor[i]^k].size()&&pv[pxor[i]^k].front()<st){
			pv[pxor[i]^k].pop();
		}
		if((!pv[pxor[i]^k].size())||pv[pxor[i]^k].front()>=i){
			continue;
		}
		ans++;
		st=i;
		// printf("%d %d %d %d %d\n",pv[pxor[i]^k].front(),pxor[i],pxor[i]^k,ans,st);
	}
	printf("%d\n",ans);
	return 0;
}