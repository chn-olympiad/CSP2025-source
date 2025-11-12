#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[10101],ans,n;
void dfs(int x,int ma,int s,int t)
{
	if(x>n)return ;
//	if(ma*2<s&&t>=3) ans++,ans%=M; 
	if(t+1>=3&&max(ma,a[x])<s)ans++,ans%=M;
	dfs(x+1,max(ma,a[x]),s+a[x],t+1);
	dfs(x+1,ma,s,t);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
 } 
