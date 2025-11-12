#include <bits/stdc++.h>
using namespace std;
long long n,m,nm,op,sum,sum1,l,r,i,j,k,a[1000005],s[1000005],mid,ans,max1=-114514114514114514,min1=114514114514114514;
bool cmp(long long nm,long long op){
	return nm>op;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]+=s[i-1]+a[i];
	}
	for(i=3;i<=n;i++){//尺取长度 
		for(l=1;l<=n-i+1;l++){//左端点 
			r=l+i-1;//右端点
			nm=s[r]-s[l-1];//区间内木条总长
			max1=-114514114514114514;
			for(j=l+1;j<=r-1;j++)max1=max(max1,a[j]);//遍历区间查找最长木条
			max1=max(max1,max(a[l],a[r]));//将剩下的左端点&右端点统计 
		//	printf("i:%lld l:%lld r:%lld max1:%lld nm:%lld\n",i,l,r,max1,nm);
			if(nm>2*max1){
				sum++;
				sum%=998244353;
			}
		}
	}
	printf("%lld",sum);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
