#include<cstdio>
using namespace std;//int能存2e20
int a[500005],s[500005],n,k;//前缀异或不会超int
long long ans;//ans存结果
int last;//用于存储上一个区间的结束,以确保不重复,默认为0
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){//s为累计前缀异或数组,a[i]^a[i+1]^...^a[j]=s[j]^s[i-1]
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		for(int j=i;j>=1;j--){
			if((s[i]^s[j-1])==k){//只记录用的最少的
				if(last<j){//如果最少的都不行,其余肯定也不行
					ans++;
					last=i;
				}
				break;
			}
		}
	}
	printf("%lld",ans);
}