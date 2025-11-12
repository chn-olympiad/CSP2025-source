#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,c[505],t,a[505],cnt,g;
long long an=1;
char s[505];
int main(){
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)if(s[i]=='1')t++;
	for(int i=1;i<=n;i++){
		a[i]=i;
		scanf("%d",&c[i]);
		if(c[i])g++;
		an=an*i%mod;
	}
	if(n<=18){
		an=0;
		do{
			int x=0,y=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0')x++;
				else{
					if(x>=c[a[i]])x++;
					else y++;
				}
			}
			if(y>=m)an++;
			if(an>=mod)an-=mod;
			cnt++;
			if(cnt>=50000000)break;
		}while(next_permutation(a+1,a+n+1));
		printf("%lld",an);
	}if(n==m){
		if(t!=n||g!=n)puts("0");
		else printf("%lld",an);
	}else if(t==n){
		printf("%lld",an);
	}else{
		
	}
	return 0;
}
