//1=C 3/4
//															  ~~~~~~~~~
//  61 | 5 - 43 | 1 - 61 | 5 - 43 | 1 - - | 5 4 43 | 3 2 21 | 1 - - | 1 - -|
//  `                 `
// ¡ª¡ª¡¶ÌýÆ¾·çÒý¡· ß÷½´ÓÍ 
#include <bits/stdc++.h>
using namespace std;
#define M 998244353
int a[505],c[505];
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,fac=1,cnt=0,ans=0,trump=1;
	scanf("%d%d%s",&n,&m,s);
	//for(int i=0;i<n;i++)s[i]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		a[i]=i;
		fac=((long long)fac*i)%M;
		trump&=(s[i-1]=='1');
	}
	if(n<=10){
		for(int kingdongun=1;kingdongun<=fac;kingdongun++){
			cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0'||cnt>=c[a[i]])cnt++;
			}
			if(n-cnt>=m)ans++;
			next_permutation(a+1,a+n+1);
		}
		printf("%d",ans);
	}
	else if(trump==1)printf("%d",fac);
	else if(m==n)printf("%d",fac*trump);
	return 0;
}/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
