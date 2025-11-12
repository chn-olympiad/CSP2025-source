#include<bits/stdc++.h>
#define int long long
using namespace std;
int vis[50],a[50],n,ans,flag;
bool check(){
	int mx=0,sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			sum+=a[i];
			mx=max(a[i],mx);
		}
	}
	return 2*mx<sum;
}void dfs(int step){
	if(step>n){
		if(check()){
			ans++;
		}
		return;
	}
	vis[step]=1;
	dfs(step+1);
	vis[step]=0;
	dfs(step+1);
}
signed main(){
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	if(flag=0){
		long long x=1;
		for(int i=1;i<=n;i++){
			x*=2;
			x%=998244353;
		}
		cout<<x;
		return 0; 
	}
	dfs(1);
	cout<<ans;
	return 0;
}
//              A                      KKK             KKK
//             A A                     K K           K K
//            A A A                    K K         K K
//           A A A A                   K K       K K
//          A A   A A                  K K     K K
//         A A     A A                 K K   K K
//        A A       A A                K K K K
//       A A         A A               K K K
//      A AAAAAAAAAAAAA A              K K K K
//     A AAAAAAAAAAAAAAA A             K K   K K
//    A A               A A            K K     K K
//   A A                 A A           K K       K K
//  A A                   A A          K K         K K
// A A                     A A         K K           K K
//AAA                       AAA        KKK             KKK