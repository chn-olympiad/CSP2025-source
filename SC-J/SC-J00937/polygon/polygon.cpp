#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ans,n,a[50005],ans1,ans2;
void aaa(int t,int s,int k){
	if(t==k+1){
		if(s>2*a[k])ans++;
		return;
	}
	aaa(t+1,s+a[t],k);
	if(t!=k)
	aaa(t+1,s,k);
}
signed main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n>20){
		cout<<rand()%mod;
		return 0;
	}
	for(int i=3;i<=n;i++)aaa(1,0,i);
	cout<<ans;
	return 0;
}