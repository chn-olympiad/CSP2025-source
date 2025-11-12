#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005,MOD=998244353;
int n;
int a[MAXN],sum[MAXN],maxx[MAXN];
int read(){
	int t;
	scanf("%d",&t);
	return t;
}
int cheng(int s){
	if(s==1) return 1;
	return (cheng(s-1)*s)%MOD;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdin);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n==3){
		if(sum[3]>a[3]*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(a[n]==1){
		cout<<cheng(n);
		return 0;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(sum[j]-sum[i]>2*a[j]){
				num++;
			}
		}
	} 
	cout<<num;
	return 0;
}
