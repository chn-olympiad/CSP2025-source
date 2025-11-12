#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353,N=50005;
long long n,m,ans,id,sum;
long long a[N];
void get_ans1(){
	for(int r=3;r<=n;r++){
		for(int i=1;i<=(1<<(r-1));i++){//二进制搜索
			sum=a[r];
			for(int j=1;j<r;j++)
				sum+=a[j]*((i%(1<<j)/(1<<(j-1))));
			if(sum>a[r]){//其实右边减了一个a[r]，但左边也减了一个a[r]，所以仍成立。 
				ans++;
				ans%=MOD;
			}
		}
	}
}
void get_ans2(){
	for(int i=1;i<=(1<<n);i++){//二进制搜索
		id=sum=0;
		for(int j=1;j<=n;j++){
			if(i%(1<<j)/(1<<(j-1)) == 1){
				sum+=a[j];
				id=j;
			}
		}
		if(sum>(a[id]*2)){
			ans++;
			ans%=MOD;
		}
	}
}
int main(){
	freopen("polygon.out","w",stdout);
	freopen("polygon.in" ,"r",stdin );
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	//1<<x 与 2^x 相等，但前者更快。
//	get_ans1();
	//t4无反应??? 
	get_ans2();
	//约O(2^n*n) t4 TLE+WA，包TLE的 
	printf("%lld",ans);
	return 0;
}
