#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MaxN = 5001;
const int MaxA = 5001;
const int Mod = 998244353;
int n,result,leave;
int arr[MaxN];
int sum[MaxN];//加到前a个数的和 

int pow2memory[MaxN] = {1,2};
int Pow2(int a){
	if(pow2memory[a]){
	}else{
		pow2memory[a] = Pow2(a-1)*2%Mod;
	}return pow2memory[a];
}

void solve(int j,int leave){
	if(leave<sum[j]){
	if(leave>=0){
		if(j>=0){
			solve(j-1,leave-arr[j]);
			solve(j-1,leave);
		}
	}else{
		result=(result+Pow2(j+1))%Mod;
	}
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;++i){
		scanf("%lld",arr+i);
		sum[i] = i>0?sum[i-1]+arr[i]:arr[i];
	}
	sort(arr,arr+n);
	for(int i=2;i<n;++i){
		solve(i-1,arr[i]);
		//printf("i:%lld result:%lld\n",i,result);
	}printf("%lld",result);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
