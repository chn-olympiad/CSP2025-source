#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],sum[N],cnt[100000],con,ans;
void dfs(int x,int start){
	if(start>n||start+x-1>n){
		return ;
	}
	memset(sum,0,sizeof(sum));
	for(int i=start;i<=start+x-1;i++){
		sum[i]=sum[i-1]+a[i+con];
//		printf("%d+%d+",sum[i-1],a[i+con]);
	}
//	cout<<" "<<sum[start+x-1]<<" "<<a[start+x-1]*2<<endl;
	if(sum[start+x-1]>a[start+x-1]*2){
		cnt[sum[start+x-1]]++;
		con=0;
		dfs(x,start+1);
	}else{
		con++;
		dfs(x,start);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
			dfs(i,j);
		}
	}
	for(int i=1;i<=100000;i++){
		if(cnt[i]!=0){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
