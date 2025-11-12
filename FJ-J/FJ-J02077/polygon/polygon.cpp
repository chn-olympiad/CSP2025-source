/*
5
1 2 3 4 5
*/
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	long long sum;
	long long max;
	int count;
	int k;
}v1,v2,v3;
int n,flag=1,a[100005]={0};
int main(){
	freopen("polygon.in","r",stdin);
	//freopen("polygon4.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag=0;
		}
	}
	if(n<=2){
		printf("0");
		return 0;
	}
	if(flag==1){
		long long b=(n*(n-1)*(n-2)/1/2/3)%998244353,ans=0;
		ans+=b;
		for(int i=4,j=n-3;i<=n;i++,j--){
			b=(b*n/i)%998244353;
			ans=(ans+b)%998244353;
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=1;i<=n;i++){
		queue<struct node> b;
		v1.sum=a[i];
		v1.max=a[i];
		v1.count=1;
		v1.k=i;
		b.push(v1);
		while(!b.empty()){
			v2=b.front();
			if(v2.count>=3&&v2.max*2<v2.sum){
				ans=(ans+1)%998244353;
			}
			b.pop();
			for(int j=v2.k+1;j<=n;j++){
				v3.sum=v2.sum+a[j];
				v3.count=v2.count+1;
				v3.max=a[j];
				v3.k=j;
				b.push(v3);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}