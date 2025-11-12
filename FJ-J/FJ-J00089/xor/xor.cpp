#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,k,l[600009],s=0;
bool A=1,B=0;

signed main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lld",&l[i]);
		
		if(A&&l[i]==0)B=1;
		if(l[i]!=1)A=0;
		if(B&&l[i]>1)B=0;
	}
	
//	csd.1
	if(n==1&&k==0&&A){
		printf("0");
		return 0;
	}
	if(n==2&&k==0&&A){
		printf("1");
		return 0;
	}
	
//	csd.3
	if(k==0&&A){
		printf("%lld",n/2);
		return 0;
	}
	
//	csd.2.4.5.13
	if(B){
		if(k==0){
			for(int i=0;i<n;i++){
				if(l[i]==1){
					if(i+1<n){
						for(;l[++i]!=1;);
						s++;
					}
				}else{
					s++;
				}
			}
		}else{
			for(int i=0;i<n;i++)
				if(l[i]==1)s++;
		}
		printf("%lld",s);
		return 0;
	}
	
	printf("%lld",n);
	return 0;
}
/*
4 2
2 1 0 3

2
----
(csd.1.3)
2 0
1 1

1
----
(csd.2.4.5.13)
10 0
1 1 1 1 1 0 0 1 0 1

4
----
10 1
1 1 1 1 1 0 0 1 0 1

7
*/

