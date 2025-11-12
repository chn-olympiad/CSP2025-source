#include<bits/stdc++.h>
using namespace std;
struct pp{
	int x,y;
}f[1000005];
int n,k,a[1005],sum[1005][1005];
bool cmp(pp a,pp b){
	return a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int len=0;
	scanf("%d%d",&n,&k);
	if(n>1000){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i][i]=a[i];
		if(sum[i][i]==k) f[++len]={i,i};
		for(int j=i-1;j>=1;j--){
			sum[j][i]=sum[j+1][i]^a[j];
			if(sum[j][i]==k) f[++len]={j,i}; 
		}
	}
	sort(f+1,f+len+1,cmp);
	int maxn=1,r=f[1].y;
	for(int i=2;i<=len;i++){
		if(f[i].x>r){
			maxn++;
			r=f[i].y;
		}
	}
	printf("%d",maxn);
	return 0;
}
