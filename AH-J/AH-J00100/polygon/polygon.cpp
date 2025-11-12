#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[5005];
int ans=0,cnt=0,maxx=-1;
void work(int now){
	if(now==n)return;
	cnt+=a[now];
	if(a[now]>=maxx)maxx=a[now];
	if(cnt>maxx*2)ans++;
	work(now++);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		work(i);
	}
	cout<<ans%MOD;
	return 0;
}
