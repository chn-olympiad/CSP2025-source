#include<cstdio>
int n,k,flag_a=-1;
int a[500001];
int weight(int x,int y){
	int w=a[x];
	for (int i=x+1;i<=y;i++) w^=a[i];
	return w; 
} 
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++) {
			if (weight(i,j)==k && i>flag_a && j>flag_a){
				ans++;
				flag_a=j;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
