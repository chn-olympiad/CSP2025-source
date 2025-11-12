#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum[5010],ans;
void dfs(int x,int sum,int len,int dep,int last){
	sum+=x;
	if(dep==len&&sum>2*x){
		ans++;
		return ;
	}
	for(int i=last+1;i<=n;i++)
		dfs(a[i],sum,len,dep+1,x);	

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++)
			dfs(a[j],0,i,1,a[j]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
