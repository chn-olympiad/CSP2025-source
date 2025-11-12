#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN];
int maxn;
int solve(int x){
	int cnt=0;
	long long now;
	int st=x;
	for(int i=x;i<=n;i++){
		if(st==i) now=a[i];
		else now^=a[i];
		if(now==k){
			cnt++;
			st=i+1;
		}
	}	
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,solve(i));
	}
	printf("%d",maxn);
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
