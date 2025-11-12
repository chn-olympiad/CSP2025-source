#include<bits/stdc++.h>
using namespace std;
const int N=5003,P=998244353;
int n,a[N],f[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		(ans+=f[a[i]+1])%=P;
		for(int j=N-1;~j;j--)(f[j]+=f[max(j-a[i],0)])%=P;
	}
	cout<<ans;
}
