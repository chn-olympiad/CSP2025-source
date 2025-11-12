#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[5005],b[5005],da,ans;
void dfs(int x,int r,int he){
	if(x==r){
		if(he>2*da)ans++;
	}
	for(int i=b[x-1];i<=n;i++){
		if(a[i]>b[x-1]){
			b[x]=a[i];
			da=max(da,a[i]);
			dfs(x+1,r,he+a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		da=0;
		dfs(0,i,0);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}