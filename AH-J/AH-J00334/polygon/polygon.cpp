#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000;
int a[N],o,p,k,n,l,cnt;
void bfs(int x,int sum,int ans){
	if(x==n){
		if(ans*2<sum)k++;
		return;
	}
	bfs(x+1,sum+a[x+1],a[x+1]);
	bfs(x+1,sum,ans);
}
signed main(){
     freopen("polygon.in","r",stdin);
     freopen("polygon.out","w",stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     cin>>n;
     for(int i=1;i<=n;i++){
		 cin>>a[i];
	 }
	 sort(a+1,a+1+n);
	 bfs(0,0,0);
	 cout<<k;
     return 0;
}
