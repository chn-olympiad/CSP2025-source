#include<bits/stdc++.h>
using namespace std;
const int MoD=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	if(n==3){
		int liar1,liar2,liar3;
		scanf("%d%d%d",&liar1,&liar2,&liar3);
		int bigLiar=max(max(liar1,liar2),liar3);
		if(liar1+liar2+liar3>2*bigLiar){
			printf("1");
		}else{
			printf("0");
		}
	}
	return 0;
} 
/*
#include<bits/stdc++.h>
using namespace std;
const long long MoD=998244353;
long long arr[5001],prev[5001],n,ans=0;
int fast_pow(long long x,long long y){
	int a=x;
	while(y>1){
		if(y%2==0){
			x=(x*x)%MoD;
			y=y>>1;
		}else{
			x=(x*x)%MoD*a%MoD;
			y=(y-1)/2;
		}
	}
	return x;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&arr[i]);
	sort(arr+1,arr+n+1,greater<int>());
	for(int i=1;i<=n;++i)prev[i]=arr[i]+prev[i-1];
	for(int i=1;i<=n-2;++i){
		if(prev[n]-prev[i]<=arr[i])continue;
		int ls=0,weak=n+1,poor=n+1,strong;
		for(int j=i+1;j<=n;--j){
			if(prev[n]-prev[j-1]<=i){
				poor=j;
				break;
			}
		}
		for(int j=i+1;j<=n;--j){
			if(arr[j]<=arr[i]/2){
				weak=j;
				break;
			}
		}
		strong=(fast_pow(2,weak-i-1)-1-(weak-i-1))%MoD;
		ls+=strong*(n-poor+1)%MoD;
	}

	return 0;
}
*/