#include<bits/stdc++.h>
using namespace std;

int n,m,sum=0,sum1=0,s=0;
char str[1000];
int a[1000];
int dfs(int x){
	if(x==n){
		return x;
	}
	for(int i=0;i<=n-1;i++){
		if(sum1<a[i]){
			if(str[i]=='0'){
				sum++;
			}
			else{
				sum1++;
			}
		}
		else{
			sum1++;
		}
	}
	if(sum==m){
		s++;	
	}
	sum=0;
	sum1=0;
	dfs(x+1);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n-1;i++){
		scanf("%c",str[i]);
	}
	for(int i=0;i<=n-1;i++){
		scanf("%d",a[i]);
	}
	printf("%d",dfs(1)%998244353);
	
	return 0;
} 
