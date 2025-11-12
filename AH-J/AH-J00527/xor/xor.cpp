#include<stdio.h>
#include<stdlib.h>
#define MAXN 500005
int n,k;
int a[MAXN];
int b[MAXN];
struct node{
	int l;int r;
}c[MAXN];
int cn;
int max;int cnt;
void dfs(int id){
	//printf("%d\n",id);
	cnt++;
	int fid=id;
	while(c[fid].l<=c[id].r&&fid<=cn)fid++;
	if(fid<=cn)dfs(fid);
	else if(cnt>max){
		max=cnt;
		return ;
	}
	cnt--;
	if(id<cn&&c[id+1].l<=c[id].r)dfs(id+1);
	else return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int aok=1,bok=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)aok=0;
		if(a[i]>1)bok=0;
		if(i>1)b[i]=b[i-1]^a[i];
		else b[i]=a[i];
	}
	if(aok){
		printf("%d",n/2);
	
	}
	else if(bok){
		int sum=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
				else {
					int j=i;
					while(a[++j]);
					sum+=(j-i)/2;
					i=j-1;
				}
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++)
				if(a[i]==1)sum++;
		}
		printf("%d",sum);
	}
	else{
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(i>1&&((b[i-1])^(b[j]))==k){
				c[++cn].l=i,c[cn].r=j;
				break;
			}
			else if(i==1&&b[j]==k){
				c[++cn].l=1,c[cn].r=j;
				break;
			}
		//for(int i=1;i<=cn;i++)printf("%d %d\n",c[i].l,c[i].r);
		//printf("%d",cn);
		dfs(1);
		printf("%d",max);
	}
	return 0;
}
