#include <bits/stdc++.h>
using namespace std;
const int maxn=5003;
int n,a[maxn],b[maxn],ans=0;
void dfs(int l,long long sum,int ceng){
	if(ceng>n){
		return;
	}
	for(int i=l;i<=n;i++){
		cout<<sum<<","<<ceng<<","<<i<<":"<<a[i]<<endl;;
		if(ceng==1&&i>n-2){
			break;
		}else if(ceng==2&&i>n-1){
			break;
		}
		if(sum>a[i]&&ceng>=3){
			ans++;
			ans%=998244353;
		}
		dfs(i+1,sum+a[i],ceng+1);
	}
	return;
}
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(1,0,1);
	printf("%d",ans);
	return 0;
}
