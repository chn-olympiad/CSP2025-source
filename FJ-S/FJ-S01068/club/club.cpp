#include <bits/stdc++.h>
using namespace std;
int t,n,arr1[210000][10],arr2[210000],ma;
long long sum;
void f(int num,int cnt1,int cnt2,int cnt3,long long sum1){
	if(num==n+1){
		if(sum1>sum)sum=sum1;
		return ;
	}
	if(cnt1<n/2)f(num+1,cnt1+1,cnt2,cnt3,sum1+arr1[num][1]);
	if(cnt2<n/2)f(num+1,cnt1,cnt2+1,cnt3,sum1+arr1[num][2]);
	if(cnt3<n/2)f(num+1,cnt1,cnt2,cnt3+1,sum1+arr1[num][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d %d %d",&arr1[i][1],&arr1[i][2],&arr1[i][3]);
			ma=max(ma,arr1[i][1]);
			ma=max(ma,arr1[i][2]);
			ma=max(ma,arr1[i][3]);
			arr2[i]=ma;
			ma=0;
		}
		if(n<=14)f(1,0,0,0,0);
		else{
			sort(arr2+1,arr2+n+1);
			for(int i=n;i>=n/2+1;--i)sum+=arr2[i];
		}		
		printf("%lld\n",sum);
		sum=0;
		for(int i=0;i<210000;++i)for(int j=0;j<10;++j)arr1[i][j]=0;
		memset(arr2,0,sizeof(arr2));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
