#include<cstdio>
#include<iostream>
using namespace std;
int n,m,s[505],c[505];
void work1(){
	long long anss=1;
	for(long long i=1;i<=n;i=i+1)anss=(anss*i)%998244353;
	printf("%lld\n",anss);
	return;
//tp01
}
void work2(){
	int i=1;
	long long cnt=0;
	while(i<=n&&s[i]==0)i=i+1;
	if(i>n){
		printf("0\n");
		return;
	}
	for(int j=1;j<=n;j=j+1)cnt=cnt+(c[j]>=i-1)?1:0;
	for(long long i=1;i<n;i=i+1)cnt=(cnt*i)%998244353;
	printf("%lld\n",cnt);
	return;
//end--
}
int a[505],b[505];
long long ans=0;
void work3(int tx){
	if(tx==n+1){
		int num=0;
		for(int i=1;i<=n;i=i+1)
			if(s[i]==0||num>=c[a[i]])num=num+1;
		if(num<=n-m)ans=ans+1;
	//dfs-fi
	}
	for(int i=1;i<=n;i=i+1){
		if(b[i]==1)continue;
		b[i]=1;
		a[tx]=i;
		work3(tx+1);
		b[i]=0;
		a[tx]=0;
	//dfs-all
	}
	if(tx==1)printf("%lld\n",ans);
	return;
//got
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i=i+1)scanf("%1d",&s[i]);
	for(int i=1;i<=n;i=i+1)scanf("%d",&c[i]);
	int sum=0;
	for(int i=1;i<=n;i=i+1)sum=sum+s[i];
	if(sum==n)work1();
	else if(sum<m)printf("0\n");
	else if(m==1)work2();
	else work3(1);
	return 0;
//end-T3
}
