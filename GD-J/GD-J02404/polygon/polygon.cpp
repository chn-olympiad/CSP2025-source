#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,ans=0,inx=0,sum=0,mx=0;
bool flg=false;
int a[N];
int vis[N];
void dfs (int deep,int j){
	if (deep==0){
		if (sum-mx*2<=1) flg=true;
		if (sum>mx*2) ans++;
		return ;
	}
	for (int i=j;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;
			sum+=a[i];
			int mx_2=mx;
			mx=max(mx,a[i]);
			dfs(deep-1,i+1);
			sum-=a[i];
			mx=mx_2;
			vis[i]=0;
			if (flg){
				flg=false;
				return ;
			}
		}
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=3;i<=n;i++) dfs(i,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
