#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,maxx;
int a[N],ans,mod=998244353;
void f(int x,int sum,int la,int iid,int id){
	if(x>id){
	if(sum>2*la)
	ans++;
	return ;
}
for(int i=iid+1;i<=n;i++)
	f(x+1,sum+a[i],a[i],i,id);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
	scanf("%lld",&a[i]);
	maxx=max(maxx,a[i]);
	}	
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	f(1,0,0,0,i);
	printf("%lld",ans);
	return 0;
}
