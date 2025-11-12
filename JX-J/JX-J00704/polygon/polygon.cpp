#include <bits/stdc++.h>
using namespace std;
const int modn = 998244353;
///long long mn[5010][13],s[13],sum[5010];
long long n,a[5010],ans;
//void work(){
//   int k=log2(n);
//    for(int i=1;i<=k;i++){
//        for(int j=1;j+s[i]-1<=n;j++){
//            f[j][i]=max(f[j-1][i-1],f[j-s[i-1]][i-1]);
//        }
//    }
//}
void dfs(long long maxn,long long sum,long long fg,long long ne){
    if( sum > maxn * 2 && fg >= 3 ){
        ans++;
    }
    for(int i=ne;i<=n;i++){
        dfs(max(maxn,a[i]),sum+a[i],fg+1,ne+1);
        dfs(maxn,sum,fg,ne+1);
    }

}
int main(){
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
//	cin>>n;
//	s[0]=1;
//	for(int i=1;i<=13;i++){
//       s[i][s[i-1]*2;
//	}
    cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
//        mn[i][0]=a[i];
	}
    dfs(0,0,0,1);
//	sum[1]=a[1];
//	for(int i=2;i<=n;i++){
//        sum[i]=sum[i-1]+a[i];
//	}
//	for(int i=1;i<=n;i++){
//        for(int j=1,j+i-1<=n;j++){
//            if()
//        }
//	}
    cout << ans % modn;
	return 0;
}
