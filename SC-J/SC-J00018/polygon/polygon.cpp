#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long cnt;
int a[5005];
void count_p(int side,int s,int m,int x){
	if(x>n) return;
	if(side==1){
		if(s>2*m){
			cnt++;
			cnt%=998244353;
		}
		return;
	}
	for(int i=1;i<=n-side+1;i++){
		count_p(side-1,s+a[x+i],max(m,a[x+i]),x+i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			count_p(i,a[j],a[j],j);
		}
	}
	printf("%lld",cnt);
	return 0;
}