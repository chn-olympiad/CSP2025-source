#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MOD=998244353;
int n,a[5010],vis[5010],ans[5010],mx[5010],tot,cnt,lans;
void check(){
	if(tot<3)return;
//	for(int i=1;i<=tot;i++)cout<<ans[i]<<" ";
//	cout<<endl<<cnt<<" "<<mx[tot]<<endl;
//	cout<<"------------"<<endl;
	if(cnt>2*mx[tot])lans=(lans+1)%MOD;
}
void dfs(int dep){
	if(dep>n)return;
	for(int i=ans[tot];i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[++tot]=i;
			cnt+=a[i];
			mx[tot]=max(mx[tot-1],a[i]);
			check();
			dfs(dep+1);
			tot--;
			cnt-=a[i];
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ans[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<lans;
	return 0;
}
