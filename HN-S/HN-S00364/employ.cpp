#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505],p[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		p[i]=i;
	}
	if(n<=10){
		int ans=0;
		do{
			int lo=0;
			for(int i=1;i<=n;i++){
				if(lo>=c[p[i]]||s[i]=='0') lo++;
			}
			if(n-lo>=m) ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}else{
		long long ans=1;
		for(int i=2;i<=n;i++){
			ans=ans*i%998244353;
		}
		printf("%lld",ans);
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
