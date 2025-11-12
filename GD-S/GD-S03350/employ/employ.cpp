#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int M=505;

char a[M];

int c[M],b[M];

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	scanf("%s",a+1);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		b[i]=i;
	}
	
	long long ans=0;
	
	do{
		int tmp=0,k=0;
		for(int i=1;i<=n;i++){
			if(tmp>=c[b[i]]||a[i]=='0'){
				tmp++;
			}else{
				k++;
			}
		}
		if(k>=m){
			ans++;
			ans=ans%(long long)(998244353);
		}
	}while(next_permutation(b+1,b+n+1));
	
	printf("%lld",ans);
	
	return 0;
}
/*
3 2
101
1 1 2

*/
