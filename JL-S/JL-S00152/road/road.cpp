#include<bits/stdc++.h>
using namespace std;
int flag1[100005]={0};
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int e[100005][1005];
int min3[100005]={2000000000};
int l[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	long long min1=200000000,min2=200000000;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(c[i]<c[min1]){
			min1=i;
		}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&d[i]);
		if(d[i]<d[min2]){
			min2=i;
		}
		for(int j=1;j<=n;j++){
			scanf("%d",&e[i][j]);
			if(e[i][j]<min3[i]){
				min3[i]=e[i][j];
				l[i]=j;
			}
		}
	}
	long long sum=0;
	while(1){
		sum+=c[min1];
		flag1[a[min1]]=1;
		flag1[b[min1]]=1;
		sum+=d[min2];
		c[min1]=200000000;
		d[min2]=200000000;
		min3[min2]=200000000;
		int ff=l[min2];
		flag1[l[min2]]=1;
		int sum2=0;
		min1=200000000;
		min2=200000000;
		for(int i=1;i<=m;i++){
			if(flag1[i]==1){
				sum2++;
			}
		}
		if(sum2>=m){
			break;
		}
		for(int i=1;i<=m;i++){
			if(c[i]<c[min1]){
				min1=i;
			}
		}
		for(int i=1;i<=k;i++){
			if(d[i]<d[min2]){
				min2=i;
			}
			min3[i]=200000000;
			for(int j=1;j<=n;j++){
				if(e[i][j]<min3[i]){
					min3[i]=e[i][j];
				}
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
