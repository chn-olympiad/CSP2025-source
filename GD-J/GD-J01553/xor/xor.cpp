#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long  c[550000][3];
struct Node{
	long long self;
	long long _2self;
}a[550000];
int f(int x){
	long long cnt=x%2;
	x/=2;
	long long nn=10;
	while(x>0){
		cnt=cnt+pow(10,(cnt+10)/10)*(x%2);
		x/=2;
	}
	return cnt;
}
int ff(long long x,long long y){
	long long cnt=0;
	while(x>0||y>0){
		if(x%10==x%10){
			cnt=cnt*10;
		}else{
			cnt=cnt*10+1;
		}
	}
	return cnt;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].self);
	}
	k=f(k);
	for(int i=1;i<=n;i++){
		a[i]._2self=f(a[i].self);
		cout<<a[i]._2self<<" ";
	}
	long long ab;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ab=ff(ab,a[i]._2self);
			if(ab==k){
				ans++;
				c[ans][1]=i;
				c[ans][2]=j;
			}
		}
	}
	long long dp[550000][550000];
	return 0;
} 
