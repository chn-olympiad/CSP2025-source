#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,k,cnt,ans,flag=1;
int a[N],pre[N],pre0[N],pre1[N];
struct Node{
	int l,r;
}b[N];
bool cmp(Node x,Node y){
	return x.r<y.r;
}
solve(){
	int now=1;
	for(int i=1;i<=n;i++){
		for(int j=now;j<=i;j++){
			int t=pre[i]^pre[j-1];
			if(t==k){
//				cout<<i<<" "<<j<<"\n";
				ans++;
				now=i+1;
				break;
			}
		}
	}
}
signed main(){
//	freopen("xor6.in","r",stdin);
//	freopen("xor1.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	pre[1]=a[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]^a[i];
	} 
//	cout<<ans<<" ";
	solve();
	printf("%lld",ans);
	return 0;
}
//^Òì»ò 

 
