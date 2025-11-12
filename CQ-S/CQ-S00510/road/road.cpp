#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,k;
struct dsb{
	long long u,v,w;
}a[1100006];
bool cmp(dsb x,dsb y){
	return x.w<y.w;
}
long long cnt;
long long f[10016];
long long gf(long long x){
	if(x==f[x])return x;
	else return f[x]=gf(f[x]);
}
long long c[16];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		cnt++;
		a[cnt].u=u,a[cnt].v=v,a[cnt].w=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			int w;
			scanf("%lld",&w);
			cnt++;
			a[cnt].u=i+n;
			a[cnt].v=j;
			a[cnt].w=w;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	long long tip=(1ll<<k);
	long long sum=1e18;
	for(int i=0;i<tip;i++){
		for(int j=1;j<=n+k;j++){
			f[j]=j;
		}
		long long ans=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<j-1)){
				ans+=c[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			long long t1=a[j].u,t2=a[j].v;
			if(t2>n){
				if((i&(1<<t2-n-1))==0){
					continue;
				}
			}
			if(t1>n){
				if((i&(1<<t1-n-1))==0){
					continue;
				}
			}
			long long f1=gf(t1),f2=gf(t2);
			if(f1!=f2){
				ans+=a[j].w;
				if(ans>=sum)break;
				f[f1]=f2;
			}
		}
		sum=min(sum,ans);
	}
	printf("%lld",sum);
	return 0;
}
/*
打了个 72 的暴力，感觉这次要死了 
72 min : 152 

优化一下本地跑挺快的，求 HYX GJY LJR 保佑，祝我多拿点分 

HYX orz
GJY orz
LJR orz

学了两年 OI csp-s 只能打172，我紫砂吧！！！！！！！！！！！


            南开三教楼，一跃解千愁
    
			人    ___________
			     | 
			     |  第三 
			     |  教学楼 
			     |
		   		 |
		   	时至今日，我终于知道了什么叫
			殊途同归。意思是管你 OI 学了
			多久，都得 一 ！ 二 ！ 三 ！
			跳！！！！！               
*/

