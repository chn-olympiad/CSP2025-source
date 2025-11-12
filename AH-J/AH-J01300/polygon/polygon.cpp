#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N],cnt=0,m;
bool f[N];
void dfs(int idx,int dep,int sum,int mx){
	if(dep==m){
		if(sum>2*mx){
			cnt++;
		}
		return ;
	}
	for(int i=idx+1;i<=n;i++){
		dfs(i,dep+1,sum+a[i],max(mx,a[i]));
	}
}
int main () {
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   if(n<=3){
	   if(n<3)cout<<0;
	   else{
		   if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))cout<<1;
		   else cout<<0;
	   }
	   return 0;
   }
   for(int i=3;i<=n;i++){
	   m=i;
	   for(int j=1;j<=n-m+1;j++){
		   dfs(j,1,a[j],a[j]);
	   }
   }
   cout<<cnt;
   return 0;
}
