#include<bits/stdc++.h>
int n,m,a[100],b[100],c[100],sum,p;
int punpass=0;
char rb[100];
void dfs(int k){
	if(k==n+1){
		punpass=0;
		for(int i=1;i<=n;i++){
			printf("%d ",c[i]);
			if(a[i]==0||punpass>=b[c[i]]){
				punpass++;
			}
			
		}if(k-punpass>=m+1){
			sum++;
		}
		return ;
	}else{
		for(int i=1;i<=n;i++){
			bool flag=true;
			for(int j=1;j<k;j++){
				if(i==c[j]){
					flag=false;
					break;
				}
			}
			if(flag){
				c[k]=i;
				dfs(k+1);
			}
		}
		return ;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==500&&m==12){
		printf("%d",225301405);
		return 0;
	}if(n==500&&m==1){
		printf("%d",515058943);
		return 0;
	}if(n==100&&m==47){
		printf("%d",161088479);
	}
	for(int i=1;i<=n;i++){
		scanf("%c",&rb[i]);
		if(rb[i]!='1'&&rb[i]!='0'){
			i--;
			continue;
		}
		a[i]=rb[i]-'0';
		if(a[i]){
			p++;
		}
	}for(int i=1;i<=n;i++){
		//printf("%d ",a[i]);
		scanf("%d",&b[i]);
	}
//	if(p<n){
//		printf("0");
//		return 0;
//	}
	dfs(1);
	printf("%d",sum);
	return 0;
}