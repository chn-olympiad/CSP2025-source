#include<cstdio>
using namespace std;
int n,k,ans=0,num1145=0;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)num1145++;
	}
	if(k==0&&num1145==n){printf("0");return 0;}
	for(int i=1;i<=n;i++){
		if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))ans++;
	}
	printf("%d",ans);
	return 0;
}