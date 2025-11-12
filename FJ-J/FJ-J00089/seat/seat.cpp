#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,s,sr,pm=1;

int c(int x){
	if(x%n==0)return x/n;
	else return x/n+1;
}

int r(int x){
	if(c(x)%2==1){
		if(x%n==0)return n;
		else return x%n;
	}else{
		if(x%n==0)return 1;
		else return n+1-x%n;
	}
}

signed main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	
	scanf("%lld",&sr);
	
	for(int i=1;i<n*m;i++){
		scanf("%lld",&s);
		if(s>sr)pm++;
	}
	
	printf("%lld %lld",c(pm),r(pm));
	return 0;
}
/*
2 2
99 100 97 98

1 2
----
3 3
94 95 96 97 98 99 100 93 92

3 1
----
3 3
4 3 5 6 7 8 9 1 2

2 1
*/

