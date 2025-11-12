#include<iostream>
#include<algorithm>
using namespace std;
int n,ans,res,a[5005];
void dfs(int x,int sum,int y,int cnt,int mx){
	if(cnt==y){
		if(sum>2*mx)
			res++;
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i],y,cnt+1,a[i]);
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
		res=0;
		for(int j=1;j<=n;j++){
			dfs(j,a[j],i,1,a[j]);
		}
		ans+=res;
	}
	cout<<ans;
	return 0;
}