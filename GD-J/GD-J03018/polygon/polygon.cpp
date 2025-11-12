#include<bits/stdc++.h>
using namespace std;
int n,a[10011],ans=0;
void dfs(int j,int num,int x){
	if(x>n)return ;
	if(x>=3)if(num>a[j]*2)ans++;	
	for(int i=j+1;i<=n;i++){
		if(x==0&&i==n-1)return ;
		else if(x==1&&i==n)return ;
		num+=a[i],dfs(i,num,x+1),num-=a[i];
	}
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0),cout<<ans;
	return 0;
}
