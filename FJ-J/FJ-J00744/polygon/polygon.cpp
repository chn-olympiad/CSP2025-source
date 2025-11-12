#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int num,int start,int sum,int max,int k){
	if(num==k){
		if(sum>max+max)
		ans++;
		return ;
	}
	for(int i=start;i<=n-k+num+1;i++)
	dfs(num+1,i+1,sum+a[i],a[i],k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		for(int i=3;i<=n;i++){
			for(int j=1;j<=(n-i+1)/2;j++)
			ans+=2*j*(n-i-j+2);
			if((n-i+1)&1)
			ans+=((n-i)/2+1)*((n-i)/2+1);
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=3;i<=n;i++)
	dfs(0,1,0,0,i);
	cout<<ans;
	return 0;
}
