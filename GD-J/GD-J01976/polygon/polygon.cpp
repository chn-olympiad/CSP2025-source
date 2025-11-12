#include<bits/stdc++.h>
using namespace std;
const int k=998244353;
int n;
long long ans;
int a[5007];
//int dfs(int i,int cnt,int o){
//	long long f=a[i][0]*2;
//	if(a[i][1]==0)
//	{
//		if(o>=3){
//			ans++;	
//		}
//		o++;
//		a[i][1]=1;
//		dfs(i+1,cnt+a[i][0],o);
//		return a[i][1]=0;;
//	}
//	dfs(i+1,cnt,o);
//	if(i==n){
//		printf0;
//	}
//}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+1+n);
	if(n<3){
		printf("0");
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<"1";
		}
		else cout<<"0";
		return 0;
	}
	long long d=n*(n-1)%k;
	printf("%d",d);
}
