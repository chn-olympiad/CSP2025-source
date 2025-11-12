#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int sum,int ma,int h,int x){
	if(sum>=n){
		if(h>ma*2&&x>=3)ans++;
		if(h+a[sum]>max(a[sum],ma)*2&&x>=2)ans++;
		return;
	}
	dfs(sum+1,max(ma,a[sum]),h+a[sum],x+1);
	dfs(sum+1,ma,h,x);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans<<endl;
    return 0;
}
