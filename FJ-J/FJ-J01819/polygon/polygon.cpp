#include<bits/stdc++.h>
using namespace std;
int n,a[10005],p[10005],sum=0;
void dfs(int x,int snm,int k,int i,int y){
	if(i>n+1) return;
	if(k>=3&&x>snm&&y){
		//cout<<x<<" "<<snm<<endl;
		sum++;
	}
	dfs(x+a[i],max(snm,a[i]*2),k+1,i+1,1);
	dfs(x,snm,k,i+1,0);
	//cout<<x<<" "<<snm<<endl;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,1,0);
	cout<<sum;
	return 0;
}
