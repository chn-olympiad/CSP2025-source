#include<bits/stdc++.h>
using namespace std;
int a[260][260];
int f[110];
int k1[100];
int sum1=1;
int xor1(int x,int y){
	int k1=x,k2=y,len1=0,len2=0;
	while(k1!=0){
		k1/=2;
		len1++;
	}
	while(k2!=0){
		k2/=2;
		len2++;
	}
	int sum=0;
	int maxi=max(len1,len2),i=0;
	while(i<maxi){
		int x1=x%2,y1=y%2;
		if(x1!=y1){
			sum+=pow(2,i);
		}
		i++;
		x/=2;
		y/=2;
	}
	return sum;
}
int maxi=0;
bool flag=false;
void dfs(int step,int end,int mb,int sum,int k){
	if(step>end){
		
		if(k==mb){
			maxi=max(maxi,sum);
		}
		return ;
	}
	k1[sum1]=step;
	sum1++;
	if(!flag){
		flag=true;
		dfs(step+1,end,mb,sum+1,a[k][f[step]]);
	}else{
		dfs(step+1,end,mb,sum,a[k][f[step]]);
	}
	k1[sum1-1]=0;
	sum1--;
	flag=false;
	dfs(step+1,end,mb,sum,k);
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=0;i<=255;i++){
		for(int j=0;j<=255;j++){
			if(i==j){
				a[i][j]=i;
			}else a[i][j]=xor1(i,j);
		}
	}
	int n,k;
	scanf("%d%d",&n,&k);
	if(n>100){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
	}
	dfs(1,n,k,0,0);
	printf("%d",maxi);
	return 0;
} 
